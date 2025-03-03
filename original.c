#include <string.h>  
#include <stdlib.h> 
#include <stdio.h> 

void vulnerable(char *input) {  
    char buffer[64]; 
    strcpy(buffer, input); // No bounds check! 
    printf("Input Argument = %s \n",buffer); 
}  

int main(int argc, char **argv) {  
    vulnerable(argv[1]);  
}  

// Unprotected compilation command
// gcc -fno-stack-protector -z execstack -no-pie original.c -o original