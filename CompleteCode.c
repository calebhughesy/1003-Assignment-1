/* This program contains several complicated elements taught within ENGG1003. Most elements of this programm will be explained
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

/* Lines 45-52 are function prototypes for "Substitutuion" Cipher. */
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

    /* Lines 61-64: Initial menu presented to user. */    
    printf("Please choose from one of the following options:\n");
    printf("\n1. Rotation\n");
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
            char message[1000], sm; // Array, "message", has been given size limit of 1000. The program will not store anything larger.
   
            /* Lines 81-83: Internal menu for encryption or decryption via rotation. */
            printf("\nPlease choose from the following options:\n");
            printf("\n1. Encryption\n");
            printf("2. Decryption\n");
            printf("\nChoice: ");
            scanf("%d", &choice); // Program reads integer value, then jumps to corresponding case value in swtich statement below.

            /* The below switch statement is specific to the "Rotation" Cipher. */
            switch(choice)
            {
                case 1: printf("\nEncryption selected.\n");
                {
                    printf("Please enter a message to encrypt (CAPITAL LETTERS ONLY): ");
                    fgetc(stdin); // Reads and stores first letter of string inputted by user in terminal (stdin). Implemented due to problems reading first letter of string.
                    fgets(message, 1000, stdin); // Stores input from stdin in "message" if under 1000 characters in size.
   
                    printf("\nEnter shift key: "); // User inputs esired shift key into terminal, stored as "key".
	                scanf("%d", &key);
	
	                for(i = 0; message[i]!= '\0'; ++i) // Syntax: intitial, condition, increment. Loop continues while conditiion is true.
	                {
		               sm = message[i]; // Message is assigned to "sm".
		
	
		               if(sm >= 'A' && sm <= 'Z') // If the letters contained in the message are between 'A' and 'Z', sm = sm + key.
		               {
		                  sm += key; // += corresponds to Left Side = Left Side + Right Side.

		                  if(sm > 'Z') // If sm is greater than 'Z', value of sm is translated back to 'A' and then shifted accordingly.
		                  {
		                      sm = sm - 'Z' + 'A' - 1;
                  		  }
			
			              message[i] = sm; // sm is then assigned back to "message" at the end of the loop.
		              } 
                    }
	               printf("\nEncrypted message: %s", message); // Resulting message is printed once the loop is exited.
	               return 0;
                }
	
            case 2: printf("\nDecryption selected.\n");
            {
                char message[1000], sm; // Same variables and values as the encryption option above.
	            int i, key;

	            printf("Please a message to decrypt (CAPITAL LETTERS ONLY): "); // User should input message that is incomprehendible.

	            fgetc(stdin);
	            fgets(message, 1000, stdin);

	            printf("\nEnter shift key: ");
	            scanf("%d", &key);

	            for(i = 0; message[i] != '\0'; ++i) // "\0" refers to the end of a message where there is no longer anything for the program to read.
	            {
		             sm = message[i];

		              if(sm >= 'A' && sm <= 'Z')
		              {
			             sm -= key; // Difference between encryption and decryption is in the +'s and -'s within the "if" loops.
			             if(sm <'A')
			             {
			                 sm = sm + 'Z' - 'A' + 1;
			             }
			             message[i] = sm;
		              }
	           }

	           printf("\nDecrypted message: %s", message); // Decrypted message printed back to user in terminal.
	           return 0;
            }

            default: printf("\nInvalid choice, restart the program.\n"); // Default statement is printed when value entered by user is not identified by program.
            return 0;
        }
        
/*===========================================================================================*/       
        
        case 2: printf("\nSubstitution Cipher selected."); 
        {
            int choice;
            char message[1000], cipher[1000], *cipher_text, *out_text, *c_text; /* "*out_text", "*cipher_text" and "*c_text" are character
            pointers. Pointers are variables that store or point to the address of another variable. */
            
            /* Lines 165-167: Menu for Substitutution Cipher. */
            printf("\nPlease choose from the following options:\n");
            printf("\n1. Encryption");
            printf("\n2. Decryption\n");
            printf("\nChoice: ");
            scanf("%d", &choice);
    
            /*Lines 174-192: Switch statement for "Substitution" Cipher. User is asked to input a message for either encryption
            or decryption, depending on their choice. The user is then presented with further instructions called from the function
            definition, which is situated after the closing bracket for "main". */
            switch(choice)
            {
                /* Message input included in swtich statements due to difficulties encountered when included in function definition. */
                case 1: printf("Enter your message (CAPITAL LETTERS ONLY): ");
                
                        fgetc(stdin);
                        fgets(message, 1000, stdin);
                        c_text = encryption(message); // "encryption(message)" assigned to "c_text", which is a pointer declared in line 161.
                break;
        
                case 2: printf("Enter your message (CAPITAL LETTERS ONLY): ");
                
                        fgetc(stdin);
                        fgets(cipher, 1000, stdin);
                        cipher_text = decryption(cipher); // "decryption(cipher)" assigned to "cipher_text", which is a pointer declared in line 161.
                break;
        
                default: printf("Invalid choice, please restart the program.");
                break;   
            }
            return 0;       
        }
        

/*===========================================================================================*/
        
        case 3: printf("\nDecryption via rotation WITHOUT key selected.\n");
        {
            char message[1000], ch;
	        int i, key = 1; // Initial value of key is set to 1.
	
	        printf("\nEnter a message to decrypt (CAPITAL LETTERS ONLY): ");
	
	        fgetc(stdin);
	        fgets(message, 1000, stdin);
	
	        while (key < 26) // "While" loop continues until the condition is no longer true.
	        {
	           /* Lines 213-229 are from "Decryption" section of "Rotation" Cipher. */
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
	           printf("\nKey: %d", key);
	           printf("\nDecrypted message: %s\n\n", message);
	
	           key++; // "key" is incremented at the bottom of the "while" loop to ensure all 25 combinations are printed to the terminal.
	       }
	       return 0;
        }
        
        default: printf("\nInvalid choice, please restart the program.\n");
        return 0;

        }
    }
} // Main function ends here. Any code after this point is function definitions for "Substitution" Cipher.


/*===========================================================================================*/

        /* Line 261: Function "char *encryption(char (out_text[]))" called. The user is asked to input a message to encrypt in the corresponding 
        swtich statement (Line 177). This statement is stored in the "message" array, whose value is then assigned to the character pointer
        "*c_text". The stored value is then recalled when the function is defined.The function ultimately substitutes the letters from the message 
        with the corresponding letters within the user's unique set of characters.
        
        Example:
        
                    Alpha: ABCDEFGHIJKLMNOPQRSTUVWXYZ
               User input: QWERTYUIOPASDFGHJKLZXCVBNM
                  Message: HELLO
        Encrypted message: ITSSG
 
        The return value of this function is the value of "out_text". The only limitation evident with this function is that the message size CANNOT 
        exceed 1000 characters in length. */
       
        char *encryption(char (out_text[]))
        {
            int i, j; // Values are incrememnted with each "for" loop.
       
            printf("\nEnter a unique set of 26 letters: "); /* User is asked to enter a unique combination of 26 letters which
            is then stored in "EncryptionKey". */
            fgets(EncryptionKey, 26, stdin);
        
            for (i = 0; i < strlen(out_text); i++) /* Condition: If the length of the string "out_text" is less than the incremented 
            counter "i", the "For" loop will run. */
            {
                for (j = 0; j < 26; j++) // Condition: If "j" is less than 26, this "for" loop will run. 
                {
                    if(alpha[j]==out_text[i]) // If the "alpha array" is equal in length to the "out_text" array, out_text = EncryptionKey.
                    {
                        out_text[i]=EncryptionKey[j];
                        break;
                    }
                }
            }
            printf("\nEncrypted message: %s", out_text); // Encrypted message is then printed in the terminal.
            return out_text;
        }
         
/*===========================================================================================*/
        
        /* Line 301: Function "char *decryption(char (out_text[]))" is called. The user is asked to input a message in the corresponding switch
        statement (Line 184) which is then stored in the character pointer "*cipher_text". The function ultimately substitutes the letters from the message 
        with the corresponding letters within the user's unique set of characters.
        
        Example:
        
             Alpha: ABCDEFGHIJKLMNOPQRSTUVWXYZ
        User input: QWERTYUIOPASDFGHJKLZXCVBNM
           Message: ITSSG
 Decrypted message: HELLO
           
        The return value of this function is the value of "out_text" . The only limitations evident with this function is that the  message size is CANNOT 
        exceed 1000 characters in length. */
       
        char *decryption(char (out_text[]))
        {
            int i, j;
            char cipher[1000];
            
            printf("\nEnter a unique set of 26 letters: "); /* User is asked to enter a unique combination of 26 letters which
            is then stored in "DecryptionKey". */
            fgets(DecryptionKey, 26, stdin);
            
            cipher[1000] = DecryptionKey[26]; // "DecryptionKey" assigned to "cipher".
            
            for(i = 0; i < strlen(out_text); i++) /* Condition: If the length of the string "out_text" is less than the incremented value of "i", the 
            "for" loop will run. */
            {
                for (j = 0; j < 26; j++) // Condition: If "j" is less than 26, the "for" loop will continue to run.
                {
                    if (DecryptionKey[j] == out_text[i]) /* If "DecryptionKey" ,incremented by "j", is equal to "out_text", incrememnted by "i", the value of "out_text"
                    incrememnted by "j" is assigned to "out_text" incrememnted by "i". */
                    {
                        out_text[i] = alpha[j];
                        break;
                    }
                }
            }
            printf("\nDecrypted message: %s", out_text); // Decrypted message stored in "out_text" is printed to terminal.
            return out_text;
        }
        
        /*===========================================================================================*/
       
       /* Reference List:
       
       Rotation Cipher: https://www.thecrazyprogrammer.com/2016/11/caesar-cipher-c-c-encryption-decryption.html
       
       Substitution Cipher: http://spceng.blogspot.com/2016/07/mono-alphabetoc-cipher-c-program.html#more */
        