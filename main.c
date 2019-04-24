/*This program enables the user to select from two different cipher types for the
purpose of encrypting or decrypting. The user is asked to choose their desired option
via the initial menu. For the rotation (or Caesar) cipher options, the user will be asked
to input their message and desired shift key into the terminal. For the substitution cipher,
all inputs will be read from the "input" file. The overall goal of this program is to provide
an easy-to-use encryption/decryption platform that displays the basics of cipher functionality.*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char inchar);


int main ()
{
    int choice;
    
        printf("Please choose from one of the following options:\n\n");
        printf("1. Encryption with rotation\n");
        printf("2. Decryption with rotation\n");
        printf("3. Encryption with substitution\n");
        printf("4. Decryption with substitution\n");
        scanf("%d", &choice);// value is read from "input" file.
        
    switch (choice)
    {
        case 1: printf("\nEncryption via rotation selected.\n");
        {
	char message[1000], ch;
	int i, key;
	
	printf("\nEnter a message to encrypt: ");
	//scanf("%[^\n]s", message);
	fgetc(stdin);
	fgets(message, 1000, stdin);
	
	printf("\nEnter shift key: ");
	scanf("%d", &key);
	
	for(i = 0; message[i]!= '\0'; ++i){
		ch = message[i];
		
	
		if(ch >= 'A' && ch <= 'Z' && NULL==0){
			ch += key;
			
			if(ch > 'Z'){
				ch -= 'Z' + 'A' - 1;
			}
			
			message[i] = ch;
		}
	}
	
	printf("\nEncrypted message: %s", message);
	
	return 0;
}
        case 2: printf("\nDecryption via rotation selected.\n");
        {
	char message[1000], ch;
	int i, key;
	
	printf("Enter a message to decrypt (CAPITAL LETTERS ONLY): ");
	
	fgetc(stdin);
	fgets(message, 1000, stdin);
	
	printf("\nEnter shift key: ");
	scanf("%d", &key);
	
	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];
		
		if(ch >= 'A' && ch <= 'Z'){
			ch -= key;
			if(ch<'A'){
			    ch += 'Z' - 'A' + 1;
			}
			message[i] = ch;
		}
	}
	
	printf("\nOriginal message: %s", message);
	
	return 0;
}
        break;
        case 3: printf("Encryption via subsitution chosen.\n");
        break;
        
/*void encrypt(char inchar)
{
  //Changing chars
  inchar = inchar + 6; //This is a simple sobstution

  //print encrypted char
  printf("%c",inchar);
}


int argc;
char** argv[100];
{
    FILE *inputFile;
    char inputBuffer[80];
    char inchar;
    int i;

    inputFile = fopen("input.txt", "r");

    //check file
    if (inputFile == NULL){ 
      printf("Failed to open\n");
      return 0;
    }else{
      //inputFile is valid so I read a string
      //and store it in inputBuffer
      fgets(inputBuffer, 80, inputFile);

      //pass every character of inputBuffer to encrypt()
      for(i=0; i<strlen(inputBuffer); i++){
    encrypt(inputBuffer[i]);
      }

    }

    printf("\n\n");
    return 0;
}*/
        case 4: printf("Decryption via substitution selected.\n");
        break;
        default: printf("Error - option not identified.");/* for any
        value other than 1-4 */
    }
    return 0;
}