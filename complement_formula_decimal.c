#include <stdio.h>
#include <math.h>
#include <string.h>

// Function to calculate 9's complement
void calculate_9_complement(char number_str[], char result[]) {
    int length = strlen(number_str);
    for (int i = 0; i < length; i++) {
        if (number_str[i] == '.') {
            result[i] = '.';
        } else {
            result[i] = '9' - number_str[i] + '0';
        }
    }
    result[length] = '\0';
}

// Function to calculate 10's complement from 9's complement
void calculate_10_complement(char num_9_complement[], char result[]) {
    int length = strlen(num_9_complement);
    int carry = 1; // Initial carry for 10's complement calculation
    
    for (int i = length - 1; i >= 0; i--) {
        if (num_9_complement[i] == '.') {
            result[i] = '.';
        } else {
            int digit = num_9_complement[i] - '0' + carry;
            if (digit == 10) {
                result[i] = '0';
                carry = 1;
            } else {
                result[i] = digit + '0';
                carry = 0;
            }
        }
    }
    result[length] = '\0';
}

int main() {
    char number_str[100];
    char num_9_complement[100];
    char num_10_complement[100];

    // Input the number
    printf("Enter number: ");
    scanf("%s", number_str);

    // Calculate 9's complement
    calculate_9_complement(number_str, num_9_complement);
    
    // Calculate 10's complement
    calculate_10_complement(num_9_complement, num_10_complement);

    // Print results
    printf("9's complement of %s: %s\n", number_str, num_9_complement);
    printf("10's complement of %s: %s\n", number_str, num_10_complement);

    return 0;
}
