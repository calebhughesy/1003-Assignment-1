/*This program enables the user to select from two different cipher types for the
purpose of encrypting or decrypting. The user is asked to choose their desired option
via the initial menu. For the rotation (or Caesar) cipher options, the user will be asked
to input their message and desired shift key into the terminal. For the substitution cipher,
all inputs will be read from the "input" file. The overall goal of this program is to provide
an easy-to-use encryption/decryption platform that displays the basics of cipher functionality.*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *encryption(char[]);
char *decryption(char[]);

size_t strlen(const char* str);
char* strcpy(char* cipher, const char* out_text);

char alpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char key[26];
char decryptionKey[26];


int main ()
{
    int choice;
    
        printf("Please choose from one of the following options:\n\n");
        printf("1. Rotation\n");
        printf("2. Substitution\n");
        printf("3. Decryption via rotation WITHOUT key\n");
        scanf("%d", &choice);// value is read from "input" file.
        
    switch (choice)
    {
        case 1: printf("\nRotation method selected.\n");
        {
   int i, choice, key;
   char message[1000], ch;

   printf("\nPlease choose from the following options:\n");
   printf("1. Encryption\n");
   printf("2. Decryption\n");
   printf("\nChoice number: ");
   scanf("%d", &choice);

   //using switch case statements
   switch(choice)
   {
   case 1: printf("Encryption selected.\n");
    {
        printf("Please enter a message to encrypt (CAPITAL LETTERS ONLY): ");
    fgetc(stdin);
    fgets(message, 1000, stdin);
   
        printf("\nEnter shift key: ");
	    scanf("%d", &key);
	
	for(i = 0; message[i]!= '\0'; ++i){
		ch = message[i];
		
	
		if(ch >= 'A' && ch <= 'Z')
		{
		  ch += key;

		 if(ch > 'Z')
		{
		  ch = ch - 'Z' + 'A' - 1;
		}
			
			message[i] = ch;
		}
	}
	
	printf("\nEncrypted message: %s", message);
	return 0;
    }
	
   case 2:
      printf("\nDecryption selected.\n");
      {
      char message[1000], ch;
	int i, key;

	printf("Please a message to decrypt (CAPITAL LETTERS ONLY): ");

	fgetc(stdin);
	fgets(message, 1000, stdin);

	printf("\nEnter shift key: ");
	scanf("%d", &key);

	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];

		if(ch >= 'A' && ch <= 'Z'){
			ch -= key;
			if(ch<'A'){
			    ch = ch + 'Z' - 'A' + 1;
			}
			message[i] = ch;
		}
	}

	printf("\nOriginal message: %s", message);
	
	return 0;
    }

    
   default:
      printf("\nError\n");
   }
   return 0;
}
/*===========================================================================================*/       
        case 2: printf("Substitution method selected.");
    
{
    int i, choice;
    char *c_text, message[1000], key[26], cipher[1000], *cipher_text, *out_text;
    
    
    printf("\nPlease choose from the following options:");
    printf("\n\n1. Encryption");
    printf("\n2. Decryption\n");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1: printf("Enter your message: ");
                fgetc(stdin);
                fgets(message, 1000, stdin);
                c_text = encryption(message);
        break;
        
        case 2: printf("Enter your message: ");
                fgetc(stdin);
                fgets(cipher, 1000, stdin);
                cipher_text = decryption(cipher);
       
        break;
        
        default: printf("Invalid choice. Please try again");
        break;
    }
}
        return 0;

        
/*===========================================================================================*/
        
        case 3: printf("Decryption via rotation WITHOUT key selected.\n");
        {
        char message[1000], ch;
	    int i, key = 1;
	
	printf("Enter a message to decrypt (CAPITAL LETTERS ONLY): ");
	
	fgetc(stdin);
	fgets(message, 1000, stdin);
	
	while (key < 26)
	{
	for(i = 0; message[i] != '\0'; ++i)
	{
		ch = message[i];
		
		if(ch >= 'A' && ch <= 'Z')
		{
			ch =  ch - 1;
			if(ch<'A')
			{
			    ch = ch + 'Z' - 'A' + 1;
			}
			message[i] = ch;
		}
	}
	printf("Key: %d", key);
	
	printf("\nDecrypted message: %s\n\n", message);
	
	key++;
	}
	return 0;
}
        
        default: printf("Error - option not identified.");/* for any
        value other than 1-4*/
    }
    return 0;
}

char *encryption(char (out_text[]))//cipher_text[])
        {
        int i, j;
        char message[1000];
       
        
        printf("\nEnter a unique combination of 26 letters: ");
        fgets(key, 26, stdin);
        
        for (i = 0; i < strlen(out_text); i++)
        {
            for (j = 0; j < 26; j++)
            {
                if(alpha[j]==out_text[i])//cipher_text[i])
                {
                    out_text[i]=key[j];
                    break;
                }
            }
        }
            printf("\nEncrypted message: %s", out_text);
            return out_text;
        }
        
        char *decryption(char (out_text[]))
        
        {
            int i, j;
            char cipher[1000];
            printf("Enter a unique combination of 26 letters: ");
            scanf("%s", decryptionKey);
            
            cipher[1000] = decryptionKey[26];
            out_text[1000] = alpha[26];
            
            
            //strcpy(cipher, out_text);
            
            for(i = 0; i < strlen(out_text); i++)
            {
                for (j = 0; j < 26; j++)
                {
                    if (decryptionKey[j] == out_text[i]) //if(out_text[i] == key[j]);
                    {
                        out_text[i] = alpha[j];
                    break;
                    }
                }
            }
            printf("\nOriginal message: %s", out_text);
            return 0;
        }

