#include <stdio.h>

int main ()
{
    char Rotation;
    char Substitution;
    
char method[2] = {Rotation, Substitution};
  printf("Please choose from one of the following encryption methods:\n - Rotation\n - Substitution\n\n");
  scanf("%s", method);
  
  printf("%s was chosen. Would you like to encrypt or decrpyt?\n", method);
  
  return 0;
}