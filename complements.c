#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void r_minus_1_complement(char* number, char* result, int base) {

    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        if (number[i] == '.') {
            result[i] = '.';
        } else {
            int digit = (number[i] >= '0' && number[i] <= '9') ? 
                    (number[i] - '0') : 
                    (number[i] - 'A' + 10);

            result[i] = (base - 1 - digit) + ( (digit >= 10) ? 'A' : '0' );
        }
    }
    result[length] = '\0';
}

void r_complement(char* r_minus_1_comp, char* result, int base) {
    int length = strlen(r_minus_1_comp);
    int carry = 1;

    for (int i = length - 1; i >= 0; i--) {
        if (r_minus_1_comp[i] == '.') {
            result[i] = '.';
            continue;
        }
        
        int digit = 0;
        if (r_minus_1_comp[i] >= '0' && r_minus_1_comp[i] <= '9') {
            digit = r_minus_1_comp[i] - '0';
        } else {
            digit = r_minus_1_comp[i] - 'A' + 10;
        }

        digit += carry;
        
        if (digit >= base) {
            result[i] = (digit - base) + ((digit >= 10) ? 'A' : '0');
            carry = 1;
        } else {
            result[i] = digit + ((digit >= 10) ? 'A' : '0');
            carry = 0;
        }
    }
    
    if (carry == 1) {
        for (int i = length; i >= 0; i--) {
            result[i + 1] = result[i];
        }
        result[0] = (carry) + ((carry >= 10) ? 'A' : '0');
    } else {
        result[length] = '\0';
    }
}

int main() {
    char number[50];
    char r_minus_1_comp[50];
    char r_comp[50];

    int base = 2; // change the value of r 

    scanf("%s", number);

    r_minus_1_complement(number, r_minus_1_comp, base);
    printf("(r-1)'s complement: %s\n", r_minus_1_comp);

    r_complement(r_minus_1_comp, r_comp, base);
    printf("r's complement: %s\n", r_comp);

    return 0;
}
