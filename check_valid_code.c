#include <stdio.h>
#include <string.h>

int is_valid_code(char* code, char* valid_codes[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(code, valid_codes[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char input[5];
    
    char* codes_8421[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001"};
    char* codes_2421[] = {"0000", "0001", "0010", "0011", "0100", "1011", "1100", "1101", "1110", "1111"};
    char* codes_84_2_1[] = {"0000", "0001", "0010", "0011", "0100", "1000", "1001", "1010", "1011", "1100"};
    
    int size_8421 = sizeof(codes_8421) / sizeof(codes_8421[0]);
    int size_2421 = sizeof(codes_2421) / sizeof(codes_2421[0]);
    int size_84_2_1 = sizeof(codes_84_2_1) / sizeof(codes_84_2_1[0]);
    
    printf("Enter a 4-bit binary code: ");
    scanf("%4s", input);
    
    int is_8421 = is_valid_code(input, codes_8421, size_8421);
    int is_2421 = is_valid_code(input, codes_2421, size_2421);
    int is_84_2_1 = is_valid_code(input, codes_84_2_1, size_84_2_1);
    
    if (is_8421 || is_2421 || is_84_2_1) {
        printf("The binary code %s is valid in the following formats:\n", input);
        if (is_8421) {
            printf("8421\n");
        }
        if (is_2421) {
            printf("2421\n");
        }
        if (is_84_2_1) {
            printf("84-2-1\n");
        }
    } else {
        printf("The binary code %s is not a valid weighted binary code.\n", input);
    }
    
    return 0;
}
