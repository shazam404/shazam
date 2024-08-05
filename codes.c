#include <stdio.h>
#include <string.h>

void get_2421_code(int digit, char* code) {
    char* codes[] = {"0000", "0001", "0010", "0011", "0100", "1011", "1100", "1101", "1110", "1111"};
    strcpy(code, codes[digit]);
}

void get_8421_code(int digit, char* code) {
    char* codes[] = {"0000", "0001", "0010", "0011", "0100", "1000", "1001", "1010", "1011", "1100"};
    strcpy(code, codes[digit]);
}

void print_codes(char* number, int format) {
    int length = strlen(number);
    char code[5];

    printf("%d \n", number);

    for (int i = 0; i < length; i++) {
        int digit = number[i] - '0';
        if (format == 1) {
            get_2421_code(digit, code);
        } else if (format == 2) {
            get_8421_code(digit, code);
        } else {
            printf("Invalid format.\n");
            return;
        }
        printf("%c: %s\n", number[i], code);
    }
}

int main() {
    char number[5];
    int format;

    printf("Enter a decimal number (1-4 digits): ");
    scanf("%4s", number);

    printf("Enter the format (2421 or 8421) (1 or 2): ");
    scanf("%d", &format);

    print_codes(number, format);

    return 0;
}

