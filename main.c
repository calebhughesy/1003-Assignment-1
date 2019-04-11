#include <stdio.h>

int main ()
{
    int Rotation = 1, Substitution = 2; /*pre-determined values
                                          of rotation and substitution for memu */
    int choice;
    char method, Encrypt, Decrypt;
    printf("Please choose from the following methods:\n1. Rotation\n2. Substitution\n");
    scanf("%d", &choice);
  printf("Option %d was chosen. Would you like to encrypt or decrpyt?\n", method);
  scanf("%c", &method);
  
  switch (method)
  {
      case 1: printf("Encryption was chosen.\n");
      break;
      case 2:  printf("Decryption was chosen.\n");
      default: printf("Choice not identified.\n");
      break;
  }
  
  return 0;
}