#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void remove_decimal(char* number, int* decimal_position) {
    int len = strlen(number);
    *decimal_position = -1;
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (number[i] == '.') {
            *decimal_position = len - i - 1;
        } else {
            number[j++] = number[i];
        }
    }
    number[j] = '\0';
}

void add_decimal(char* number, int decimal_position) {
    if (decimal_position == -1) return;
    
    int len = strlen(number);
    for (int i = len; i > len - decimal_position; i--) {
        number[i] = number[i-1];
    }
    number[len - decimal_position] = '.';
    number[len + 1] = '\0';
}

void r_complement(char* number, char* result, int length, int base) {
    for (int i = 0; i < length; i++) {
        int digit = (number[i] >= 'A') ? (number[i] - 'A' + 10) : (number[i] - '0');
        int complement_digit = base - 1 - digit;
        result[i] = (complement_digit >= 10) ? (complement_digit - 10 + 'A') : (complement_digit + '0');
    }
    result[length] = '\0';

    // Add 1 to the complement
    int carry = 1;
    for (int i = length - 1; i >= 0; i--) {
        int digit = (result[i] >= 'A') ? (result[i] - 'A' + 10) : (result[i] - '0');
        digit += carry;
        if (digit == base) {
            result[i] = '0';
            carry = 1;
        } else {
            result[i] = (digit >= 10) ? (digit - 10 + 'A') : (digit + '0');
            carry = 0;
        }
    }
}

void addition(char* number1, char* number2, char* result, int base) {
    int carry = 0;
    int length1 = strlen(number1);
    int length2 = strlen(number2);
    int maxLength = (length1 > length2) ? length1 : length2;
    
    for (int i = 0; i < maxLength; i++) {
        int digit1 = (i < length1) ? 
            (number1[length1 - 1 - i] >= 'A' ? number1[length1 - 1 - i] - 'A' + 10 : 
            number1[length1 - 1 - i] - '0') : 0;

        int digit2 = (i < length2) ? 
            (number2[length2 - 1 - i] >= 'A' ? 
            number2[length2 - 1 - i] - 'A' + 10 : 
            number2[length2 - 1 - i] - '0') : 0;
        
        int sum = digit1 + digit2 + carry;
        carry = sum / base;
        int sum_digit = sum % base;
        
        result[maxLength - 1 - i] = (sum_digit >= 10) ? (sum_digit - 10 + 'A') : (sum_digit + '0');
    }
    
    if (carry) {
        for (int i = maxLength; i > 0; i--) {
            result[i] = result[i - 1];
        }
        result[0] = '1';
        result[maxLength + 1] = '\0';
    } else {
        result[maxLength] = '\0';
    }
}

int compare_numbers(char* number1, char* number2) {
    int len1 = strlen(number1);
    int len2 = strlen(number2);
    
    if (len1 != len2) {
        return len1 - len2;
    }
    
    return strcmp(number1, number2);
}

void subtraction(char* number1, char* number2, char* result, int* is_negative, int base) {
    char r_comp[50];
    char temp_result[50];
    int length1 = strlen(number1);
    int length2 = strlen(number2);
    int maxLength = (length1 > length2) ? length1 : length2;

    // Pad the shorter number with zeros
    char padded_number1[50] = {0};
    char padded_number2[50] = {0};
    for (int i = 0; i < maxLength - length1; i++) padded_number1[i] = '0';
    strcat(padded_number1, number1);
    for (int i = 0; i < maxLength - length2; i++) padded_number2[i] = '0';
    strcat(padded_number2, number2);

    if (compare_numbers(padded_number1, padded_number2) < 0) {
        // If number2 is greater, swap the numbers and set is_negative
        r_complement(padded_number2, r_comp, maxLength, base);
        addition(padded_number1, r_comp, temp_result, base);
        r_complement(temp_result, result, strlen(temp_result), base);
        *is_negative = 1;
    } else {
        r_complement(padded_number2, r_comp, maxLength, base);
        addition(padded_number1, r_comp, result, base);
        *is_negative = 0;
    }

    // Remove leading zeros
    int i = 0;
    while (result[i] == '0' && result[i+1] != '\0') i++;
    memmove(result, result + i, strlen(result) - i + 1);
}

int main() {
    char number1[50], number2[50];
    char addition_result[50], subtraction_result[50];
    int decimal1, decimal2;
    int is_negative;
    int base;

    // Read base and two numbers from input
    printf("Enter the base: ");
    scanf("%d", &base);
    printf("Enter the first number: ");
    scanf("%s", number1);
    printf("Enter the second number: ");
    scanf("%s", number2);

    // Remove decimal points from the numbers
    remove_decimal(number1, &decimal1);
    remove_decimal(number2, &decimal2);

    // Perform addition
    addition(number1, number2, addition_result, base);
    int decimal_add = (decimal1 > decimal2) ? decimal1 : decimal2;
    add_decimal(addition_result, decimal_add);
    printf("Addition: %s\n", addition_result);

    // Perform subtraction
    subtraction(number1, number2, subtraction_result, &is_negative, base);
    int decimal_sub = (decimal1 > decimal2) ? decimal1 : decimal2;
    add_decimal(subtraction_result, decimal_sub);
    printf("Subtraction: %s%s\n", is_negative ? "-" : "", subtraction_result);

    return 0;
}