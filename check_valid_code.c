#include <stdio.h>
#include <string.h>

int main() {
    // Define arrays of string literals
    const char *weighted8421[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001"};
    const char *weighted2421[] = {"0000", "0001", "0010", "0011", "0100", "1011", "1100", "1101", "1110", "1111"};
    const char *weighted84_2_1[] = {"0000", "0111", "0110", "0101", "0100", "1011", "1010", "1001", "1000", "1111"};
    
    char input_str[5];  // Increased size to accommodate null terminator
    printf("Enter a 4-bit binary string: ");
    scanf("%4s", input_str);  // Limit input to 4 characters to avoid buffer overflow

    int found = 0;

    // Check in weighted8421
    for (int i = 0; i < 10; i++) {
        if (strcmp(weighted8421[i], input_str) == 0) {
            printf("Present in 8421\n");
            found = 1;
        }
    }
    
    // Check in weighted2421
        for (int i = 0; i < 10; i++) {
            if (strcmp(weighted2421[i], input_str) == 0) {
                printf("Present in 2421\n");
                found = 1;
                break; // Stop after finding the match
            }
        }
    
    
    // Check in weighted84_2_1
        for (int i = 0; i < 10; i++) {
            if (strcmp(weighted84_2_1[i], input_str) == 0) {
                printf("Present in 84-2-1\n");
                found = 1;
            }
        }
    
    
    // If not found in any array
    if (!found) {
        printf("Not present in any array\n");
    }

    return 0;
}
