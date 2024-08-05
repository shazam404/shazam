#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void decimal_to_excess3(int digit, char* code) {
    const char* codes_excess3[] = {"0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100"};
    strcpy(code, codes_excess3[digit]);
}

void r_minus_1_complement(char* bin_code) {
    for (int i = 0; bin_code[i] != '\0'; i++) {
        bin_code[i] = (bin_code[i] == '0') ? '1' : '0';
    }
}

void binary_addition(char* a, char* b, char* result, int length) {
    int carry = 0, sum;

    for (int i = length - 1; i >= 0; i--) {
        sum = (a[i] - '0') + (b[i] - '0') + carry;
        result[i + 1] = (sum % 2) + '0';
        carry = sum / 2;
    }
    result[0] = carry + '0';
}

int excess3_to_decimal(char* bin_code) {
    int decimal = 0;
    for (int i = 0; i < strlen(bin_code); i += 4) {
        char digit_bin[5];
        strncpy(digit_bin, &bin_code[i], 4);
        digit_bin[4] = '\0';

        int digit = 0;
        for (int j = 0; j < 4; j++) {
            digit = (digit << 1) | (digit_bin[j] - '0');
        }
        decimal = decimal * 10 + (digit - 3);
    }
    return decimal;
}

void complement_subtraction(double num1, double num2) {
    char bin_num1[13] = {0}, bin_num2[13] = {0}, comp_num2[13] = {0}, result[14] = {0};
    char temp_bin[5];
    
    int temp_num1 = (int)(num1 * 100);
    int temp_num2 = (int)(num2 * 100);
    
    for (int i = 11; i >= 0; i -= 4) {
        decimal_to_excess3(temp_num1 % 10, &bin_num1[i - 3]);
        decimal_to_excess3(temp_num2 % 10, &bin_num2[i - 3]);
        temp_num1 /= 10;
        temp_num2 /= 10;
    }

    strcpy(comp_num2, bin_num2);
    r_minus_1_complement(comp_num2);
    binary_addition(bin_num1, comp_num2, result, 12);

    if (result[0] == '1') {
        for (int i = 12; i >= 0; i--) {
            if (result[i] == '0') {
                result[i] = '1';
                break;
            } else {
                result[i] = '0';
            }
        }
    }

    int decimal_result = excess3_to_decimal(result + 1);

    printf("%.2lf\n", decimal_result / 100.0);
}

int main() {
    double num1, num2;
    
    scanf("%lf", &num1);
    scanf("%lf", &num2);
    
    complement_subtraction(num1, num2);
    
    return 0;
}
