/*This program enables the user to select from two different cipher types for the
purpose of encrypting or decrypting. The user is asked to choose their desired option
via the initial menu. For the rotation (or Caesar) cipher options, the user will be asked
to input their message and desired shift key into the terminal. For the substitution cipher,
all inputs will be read from the "input" file. The overall goal of this program is to provide
an easy-to-use encryption/decryption platform that displays the basics of cipher functionality.*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

   printf("\nPlease choose following options:\n");
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
        
        case 2: printf("Substitution method selected.");
        break;
        
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
