#include <stdio.h>
int main ()
{
    int choice;
    
        printf("Please choose from one of the following options:\n\n");
        printf("1. Encryption with rotation\n");
        printf("2. Decryption with rotation\n");
        printf("3. Encryption with substitution\n");
        printf("4. Decyrption with substitution\n");
        scanf("%d", &choice);// value is read from "input" file.
        
    switch (choice)
    {
        case 1: printf("\nOption 1 selected.\n");
        {
	char message[] = "input.txt", msg, ch;
	int i, key;
	
	//FILE *inFile;
	//inFile = fopen(message, "r");
	//fscanf(inFile, "%c", &msg);
	printf("\nEnter a message to encrypt: \n");
	gets(message);
	printf("Enter shift key: \n");
	scanf("%d", &key);
	
	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];
		
	
		if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;
			
			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}
			
			message[i] = ch;
		}
	}
	
	printf("Encrypted message: %s", message);
	
	return 0;
}
        case 2: printf("\nOption 2 selected.\n");
        {
	char message[100], ch;
	int i, key;
	
	printf("Enter a message to decrypt (CAPITAL LETTERS ONLY): ");
	gets(message);
	//scanf("%s", message);
	printf("Enter shift key: ");
	scanf("%d", &key);
	
	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];
		
		if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;
			
			message[i] = ch;
		}
	}
	
	printf("Original message: %s", message);
	
	return 0;
}
        break;
        case 3: printf("Option 3 selected.\n");
        break;
        case 4: printf("Option 4 selected.\n");
        break;
        default: printf("Error - option not identified.");/* for any
        value other than 1-4 */
    }
    return 0;
}