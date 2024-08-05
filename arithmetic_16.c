#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void r_minus_1_complement(char* number, char* result) {
    int length = strlen(number);
    for (int i = 0; i < length; i++) {
        if (number[i] == '.') {
            result[i] = '.';
        } else {
            int digit = (number[i] >= 'A') ? (number[i] - 'A' + 10) : (number[i] - '0');
            int complement_digit = 15 - digit;
            result[i] = (complement_digit >= 10) ? (complement_digit - 10 + 'A') : (complement_digit + '0');
        }
    }
    result[length] = '\0';
}

void r_complement(char* r_minus_1_comp, char* result) {
    int length = strlen(r_minus_1_comp);
    int carry = 1;

    for (int i = length - 1; i >= 0; i--) {
        if (r_minus_1_comp[i] == '.') {
            result[i] = '.';
            continue;
        }
        
        int digit = (r_minus_1_comp[i] >= 'A') ? (r_minus_1_comp[i] - 'A' + 10) : (r_minus_1_comp[i] - '0');
        digit += carry;
        
        if (digit == 16) {
            result[i] = '0';
            carry = 1;
        } else {
            result[i] = (digit >= 10) ? (digit - 10 + 'A') : (digit + '0');
            carry = 0;
        }
    }
    
    if (carry == 1) {
        for (int i = length; i >= 0; i--) {
            result[i + 1] = result[i];
        }
        result[0] = '1';
    } else {
        result[length] = '\0';
    }
}

void addition(char* number1, char* number2, char* result) {

    int carry = 0;
    int length1 = strlen(number1);
    int i = length1;
    int length2 = strlen(number2);
    int maxLength = (length1 > length2) ? length1 : length2;
    
    result[maxLength + 1] = '\0';

    for (i = 0; i < maxLength; i++) {
        int digit1 = (i < length1 && number1[length1 - 1 - i] != '.') ? 
            (number1[length1 - 1 - i] >= 'A' ? number1[length1 - 1 - i] - 'A' + 10 : 
            number1[length1 - 1 - i] - '0') : 0;

        int digit2 = (i < length2 && number2[length2 - 1 - i] != '.') ? 
            (number2[length2 - 1 - i] >= 'A' ? 
            number2[length2 - 1 - i] - 'A' + 10 : 
            number2[length2 - 1 - i] - '0') : 0;
        
        int sum = digit1 + digit2 + carry;
        carry = sum / 16;
        int sum_digit = sum % 16;
        
        result[maxLength - 1 - i] = (sum_digit >= 10) ? (sum_digit - 10 + 'A') : (sum_digit + '0');

    }
    
    if (carry) {
        for (i = maxLength; i > 0; i--) {
            result[i] = result[i - 1];
        }
        result[0] = carry + '0';
    } else {
        result[maxLength] = '\0';
    }
}

void subtraction(char* number1, char* number2, char* result) {
    char r_minus_1_comp[50];
    char r_comp[50];
    char temp_result[50];
    int length1 = strlen(number1);
    int length2 = strlen(number2);

    r_minus_1_complement(number2, r_minus_1_comp);
    r_complement(r_minus_1_comp, r_comp);

    addition(number1, r_comp, temp_result);

    int length = strlen(temp_result);
    if (length > length1) {
        strcpy(result, temp_result + 1);
    } else {
        strcpy(result, temp_result);
    }
}

int main() {
    char number1[50];
    char number2[50];
    char addition_result[50];
    char subtraction_result[50];

    scanf("%s", number1);
    scanf("%s", number2);

    addition(number1, number2, addition_result);
    printf("Addition: %s\n", addition_result);

    subtraction(number1, number2, subtraction_result);
    printf("Subtraction: %s\n", subtraction_result);

    return 0;
}
