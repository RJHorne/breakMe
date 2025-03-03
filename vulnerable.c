#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insecure_copy(char* input) {
    char buffer[16];
    strcpy(buffer, input); 
    printf("Username: %s \n",buffer);
}

void unsafe_input() {
    char credentials[32];
    printf("Enter admin password: ");
    gets(credentials); 
}

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    
    insecure_copy(argv[1]);
    unsafe_input();
    
    printf("Program completed normally\n");
    return 0;
}
