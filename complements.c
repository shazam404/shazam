#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate r-1 complement using the formula method
void r_minus_1_complement(char* number, char* result, int base) {
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        if (number[i] == '.') {
            result[i] = '.';
        } else {
            int digit = (number[i] >= '0' && number[i] <= '9') ? 
                        (number[i] - '0') :
                        (number[i] - 'A' + 10);

            int comp_digit = base - 1 - digit;

            result[i] = (comp_digit < 10) ? (comp_digit + '0') : (comp_digit - 10 + 'A');
        }
    }
    result[length] = '\0';
}

// Function to calculate r complement using the formula method
void r_complement(char* r_minus_1_comp, char* result, int base) {
    int length = strlen(r_minus_1_comp);
    int carry = 1;

    for (int i = length - 1; i >= 0; i--) {
        if (r_minus_1_comp[i] == '.') {
            result[i] = '.';
            continue;
        }

        int digit = (r_minus_1_comp[i] >= '0' && r_minus_1_comp[i] <= '9') ? 
                    (r_minus_1_comp[i] - '0') :
                    (r_minus_1_comp[i] - 'A' + 10);

        digit += carry;

        if (digit >= base) {
            result[i] = (digit - base < 10) ? (digit - base + '0') : (digit - base - 10 + 'A');
            carry = 1;
        } else {
            result[i] = (digit < 10) ? (digit + '0') : (digit - 10 + 'A');
            carry = 0;
        }
    }

    if (carry == 1) {
        for (int i = length; i >= 0; i--) {
            result[i + 1] = result[i];
        }
        result[0] = '1';
        result[length + 1] = '\0';
    } else {
        result[length] = '\0';
    }
}

int main() {
    char number[50];
    char r_minus_1_comp[50];
    char r_comp[50];

    int base = 10; // Change the base value as needed

    printf("Enter number: ");
    scanf("%s", number);

    r_minus_1_complement(number, r_minus_1_comp, base);
    printf("(r-1)'s complement: %s\n", r_minus_1_comp);

    r_complement(r_minus_1_comp, r_comp, base);
    printf("r's complement: %s\n", r_comp);

    return 0;
}
