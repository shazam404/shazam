#include <stdio.h>
#include <string.h>

// Function to convert Gray code to Binary code
void grayToBinary(const char* gray, char* binary, int n) {
    binary[0] = gray[0]; // The MSB of Gray code is the same as the MSB of Binary code
    for (int i = 1; i < n; i++) {
        binary[i] = (gray[i] == binary[i-1]) ? '0' : '1'; // Binary[i] = Gray[i] XOR Binary[i-1]
    }
    binary[n] = '\0'; // Null-terminate the string
}

// Function to convert Binary code to Gray code
void binaryToGray(const char* binary, char* gray, int n) {
    gray[0] = binary[0]; // The MSB of Binary code is the same as the MSB of Gray code
    for (int i = 1; i < n; i++) {
        gray[i] = (binary[i] == binary[i-1]) ? '0' : '1'; // Gray[i] = Binary[i] XOR Binary[i-1]
    }
    gray[n] = '\0'; // Null-terminate the string
}

int main() {
    char input[100];
    char result[100];
    int n ;// Fixed to 8 bits
    printf("enter no. of bits");
    scanf("%d",&n);
    printf("Enter the 8-bit code (Gray or Binary): ");
    scanf("%s", input);

    // Validate input length
    if (strlen(input) != n) {
        printf("Input length does not match specified n.\n");
        return 1;
    }

    printf("Choose conversion:\n1. Gray code to Binary code\n2. Binary code to Gray code\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            grayToBinary(input, result, n);
            printf("Binary code: %s\n", result);
            break;
        case 2:
            binaryToGray(input, result, n);
            printf("Gray code: %s\n", result);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    return 0;
}
