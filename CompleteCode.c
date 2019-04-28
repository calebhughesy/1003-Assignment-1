/*This program contains several complicated elements taught within ENGG1003. Most elements of this programm will be explained
through commenting, with the more advanced elements explained in greater detail.

This program requires the user to input integers and letters in the terminal throughout its entirety. There will be various
menus with several options that the user will need to choose from in order to reach their desired method. When presented with
a menu, the user will be asked to input the integer corresponding to their desired choice.

Example:

"Please choose from one of the following:

1. Rotation
2. Substitution
3. Decryption via rotation without key"

If the user wishes to select "Rotation", the user must type "1<enter>" into the terminal.

There are two types of cipher used in this program:

1. Rotation (Caesar) Cipher: Shifts the letters inputted by the user by the "shift key" number.

Example:

Message: HELLO, Shift Key: 3, Encrypted message: KHOOR.

2. Substitution Cipher: Swaps the letters inputted by the user with a letter from a unique combination of letters
also implemented by the user.

Example: Message: HELLO, Unique combination of letters: QWERTYUIOPASDFGHJKLZXCVBNM, Encrypted message: ITSSG.

One other option is available to the user: Decryption via rotation without key. This sub-program requires the user
to input a message in the terminal but does NOT ask the user to input a shift key. Instead, the program runs on a loop, 
showing each possible combination of letters. The user can then identify the message that is comprehendible along with
its associated shift key.

To restart the program, the user must type "./a.out<enter>" into the terminal.*/


/* Lines 42-44: Header files. Program cannot operate without them. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Lines 47-55 are function prototypes for "Substitutuion" Cipher. */
char *encryption(char[]); // Asterisk (*) indicates pointer.
char *decryption(char[]); // Pointer has argument of type char with an unknown size.
size_t strlen(const char* str);

/* Line 50: Array has hard-coded set of variables used as the alphabet in the Substitution Cipher. */
char alpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char EncryptionKey[26]; // Key values are determined by user, but size is restricted.
char DecryptionKey[26];

/*===========================================================================================*/

int main ()
{
    int choice;

    /* Lines 60-63: Initial menu presented to user. */    
    printf("Please choose from one of the following options:\n\n");
    printf("1. Rotation\n");
    printf("2. Substitution\n");
    printf("3. Decryption via rotation WITHOUT key\n");
    printf("\nChoice: ");
    scanf("%d", &choice); // Program scans for integer inputted by user.
     
    /* Switch statements are used for jumping to the case containing the program corresponding to the integer
    inputted by the user. For example, if the user entered "1<enter> into the terminal", the program would jump
    to "case 1" inside of the switch statement. */
    
    /* The below switch statement is used for selecting between the different cipher types. */
    switch (choice)
    {
        case 1: printf("\nRotation Cipher selected.\n");
        {
            int i, choice, key; // "i" is for increment.
            char message[1000], ch; // Array, "message", has been given size limit of 1000. The program will not store anything larger.
   
            /* Lines 78-80: Internal menu for encryption or decryption via rotation. */
            printf("\nPlease choose from the following options:\n");
            printf("1. Encryption\n");
            printf("2. Decryption\n");
            printf("\nChoice: ");
            scanf("%d", &choice); // Program reads integer value, then jumps to corresponding case value in swtich statement below.

  
            switch(choice)
            {
                case 1: printf("Encryption selected.\n");
                {
                    printf("Please enter a message to encrypt (CAPITAL LETTERS ONLY): ");
                    fgetc(stdin); // Reads and stores first letter of string inputted by user in terminal (stdin). Implemented due to problems reading first letter of string.
                    fgets(message, 1000, stdin); // Reads entire string from stdin.
   
                    printf("\nEnter shift key: "); // User inputs esired shift key into terminal, stored as "key".
	                scanf("%d", &key);
	
	                for(i = 0; message[i]!= '\0'; ++i) // Syntax: intitial, condition, increment. Loop continues while conditiion is true.
	                {
		              ch = message[i]; // Message is assigned to "ch".
		
	
		              if(ch >= 'A' && ch <= 'Z') // If the letters contained in the message are between 'A' and 'Z', ch = ch + key.
		              {
		                  ch += key; // += corresponds to Left Side = Left Side + Right Side.

		                  if(ch > 'Z') // If ch is greater than 'Z', value of ch is translated back to 'A' and then shifted accordingly.
		                  {
		                      ch = ch - 'Z' + 'A' - 1;
                  		  }
			
			              message[i] = ch; // ch is then assigned back to "message" at the end of the loop.
		              } 
                    }
	               printf("\nEncrypted message: %s", message); // Resulting message is printed once the loop is exited.
	               return 0;
                }
	
            case 2: printf("\nDecryption selected.\n");
            {
                char message[1000], ch; // Same variables and values as the encryption option above.
	            int i, key;

	            printf("Please a message to decrypt (CAPITAL LETTERS ONLY): "); // User should input message that is incomprehendible.

	            fgetc(stdin);
	            fgets(message, 1000, stdin);

	            printf("\nEnter shift key: ");
	            scanf("%d", &key);

	            for(i = 0; message[i] != '\0'; ++i)
	            {
		             ch = message[i];

		              if(ch >= 'A' && ch <= 'Z')
		              {
			             ch -= key; // Difference between encryption and decryption is in the +'s and -'s within the "if" loops.
			             if(ch<'A')
			             {
			                 ch = ch + 'Z' - 'A' + 1;
			             }
			             message[i] = ch;
		              }
	           }

	           printf("\nDecrypted message: %s", message); // Decrypted message printed back to user in terminal.
	           return 0;
            }

            default: printf("\nInvalid choice, please try again.\n"); // Default statement is printed when value entered by user is not identified by program.
            return 0;
        }
        
/*===========================================================================================*/       
        
        case 2: printf("Substitution Cipher selected."); 
        {
            int i, choice;
            char *c_text, message[1000], cipher[1000], *cipher_text; // "*c_text" and "*cipher_text" are pointers.
            
            /* Lines 164-166: Menu for Substitutution Cipher. */
            printf("\nPlease choose from the following options:");
            printf("\n\n1. Encryption");
            printf("\n2. Decryption\n");
            printf("\nChoice: ");
            scanf("%d", &choice);
    
            switch(choice)
            {
                case 1: printf("Enter your message: "); // Message input included in swtich statements due to difficulties encountered when included in function definition.
                
                    fgetc(stdin);
                    fgets(message, 1000, stdin);
                    c_text = encryption(message); // "encryption(message)" assigned to c_text, which has a pointer initialised in line 161.
                break;
        
                case 2: printf("Enter your message: ");
                
                        fgetc(stdin);
                        fgets(cipher, 1000, stdin);
                        cipher_text = decryption(cipher); // "decryption(cipher)" assigned to cipher_text, which has a pointer inititalised in line 161.
                break;
        
                default: printf("Invalid choice, please try again.");
                break;   
            }
            return 0;       
        }
        

/*===========================================================================================*/
        
        case 3: printf("Decryption via rotation WITHOUT key selected.\n");
        {
            char message[1000], ch;
	        int i, key = 1; // Initial value of key is set to 1.
	
	        printf("Enter a message to decrypt (CAPITAL LETTERS ONLY): ");
	
	        fgetc(stdin);
	        fgets(message, 1000, stdin);
	
	        while (key < 26) // "While" loop continues until the condition is no longer true.
	        {
	           /* Lines 208-220 are from "Decryption" section of "Rotation" Cipher. */
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
	
	           key++; // "key" is incremented at the bottom of the "while" loop to ensure all 25 combinations are printed to the terminal.
	       }
	       return 0;
        }
        
        default: printf("\nInvalid choice, please try again.\n");
        return 0;

        }
    }
} // Main function ends here. Any program after here is function definitions for "Substitution" Cipher


/*===========================================================================================*/

char *encryption(char (out_text[]))
        {
        int i, j;
       
        printf("\nEnter a unique combination of 26 letters: ");
        fgets(EncryptionKey, 26, stdin);
        
        for (i = 0; i < strlen(out_text); i++)
        {
            for (j = 0; j < 26; j++)
            {
                if(alpha[j]==out_text[i])
                {
                    out_text[i]=EncryptionKey[j];
                    break;
                }
            }
        }
            printf("\nEncrypted message: %s", out_text);
            return out_text;
        }
         
/*===========================================================================================*/
       
        char *decryption(char (out_text[]))
        
        {
            int i, j;
            char cipher[1000];
            printf("Enter a unique combination of 26 letters: ");
            scanf("%s", DecryptionKey);
            
            cipher[1000] = DecryptionKey[26];
            out_text[1000] = alpha[26];
            
            
            for(i = 0; i < strlen(out_text); i++)
            {
                for (j = 0; j < 26; j++)
                {
                    if (DecryptionKey[j] == out_text[i])
                    {
                            out_text[i] = alpha[j];
                    break;
                    }
                }
            }
            printf("\nOriginal message: %s", out_text);
            return 0;
        }