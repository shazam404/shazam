#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void binary_to_gray(char* binary, char* gray) {
    int length = strlen(binary);
    // find msb
    int index = 0;
    for(int i = 0; i < length; i++) {
        if(binary[i] == '1') {
            gray[0] = '1';
            index = i;
            break;
        }
        gray[i] = '0';
    }

    for (int i = index; i < length - 1; i++) {
        gray[i + 1] = (binary[i] == binary[i + 1]) ? '0' : '1';
    }
    gray[length] = '\0';
}

void gray_to_binary(char* gray, char* binary) {
    int length = strlen(gray);
    int index = 0;
    for(int i = 0; i < length; i++) {
        if(gray[i] == '1') {
            binary[i] = '1';
            index = i;
            break;
        }
        binary[0] = '0';
    }

    for (int i = index; i < length - 1; i++) {
        binary[i + 1] = (gray[i] == binary[i]) ? '0' : '1';
    }
    binary[length] = '\0';

}

int main() {
    char input[10]; 
    char result[50]; 
    
    printf("Enter an n-bit binary or Gray code: ");
    scanf("%10s", input);
    char code_type;
    printf("Enter the type of code (B for binary, G for Gray): ");
    scanf(" %c", &code_type);

    if (code_type == 'B') {
        binary_to_gray(input, result);
        printf("Gray code: %s\n", result);
    } else if (code_type == 'G') {
        gray_to_binary(input, result);
        printf("Binary code: %s\n", result);
    } else {
        printf("Invalid code type.\n");
    }
    
    return 0;
}
