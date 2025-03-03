#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void vulnerable(const char *input) {
    if (input == NULL) {
        printf("Error: Input is NULL\n");
        return;
    }

    size_t input_length = strlen(input);
    if (input_length >= 100) {
        printf("Error: Input is too long (max 99 characters)\n");
        return;
    }

    char *buffer = malloc(100);
    if (buffer == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }

    strncpy(buffer, input, 99);
    buffer[99] = '\0';  // Ensure null-termination

    printf("Processed input: %s\n", buffer);

    free(buffer);  // Free allocated memory
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    vulnerable(argv[1]);
    return 0;
}
