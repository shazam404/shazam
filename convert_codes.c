#include <stdio.h>
#include <string.h>

const char* codes_8421[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001"};
const char* codes_2421[] = {"0000", "0001", "0010", "0011", "0100", "1011", "1100", "1101", "1110", "1111"};
const char* codes_84_2_1[] = {"0000", "0001", "0010", "0011", "0100", "1000", "1001", "1010", "1011", "1100"};

int find_index(const char* code, const char* codes[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(code, codes[i]) == 0) {
            return i;
        }
    }
    return -1; 
}

char** get_codes_array(const char* format, int* size) {
    if (strcmp(format, "8421") == 0) {
        *size = sizeof(codes_8421) / sizeof(codes_8421[0]);
        return codes_8421;
    } else if (strcmp(format, "2421") == 0) {
        *size = sizeof(codes_2421) / sizeof(codes_2421[0]);
        return codes_2421;
    } else if (strcmp(format, "84-2-1") == 0) {
        *size = sizeof(codes_84_2_1) / sizeof(codes_84_2_1[0]);
        return codes_84_2_1;
    } else {
        *size = 0;
        return NULL;
    }
}

int main() {
    char input_code[5];
    char input_format[7];
    char output_format[7];
    
    printf("Enter a 4-bit binary code: ");
    scanf("%4s", input_code);
    
    printf("Enter the input format (8421, 2421, 84-2-1): ");
    scanf("%6s", input_format);
    
    printf("Enter the output format (8421, 2421, 84-2-1): ");
    scanf("%6s", output_format);
    
    int input_size, output_size;
    const char** input_codes = get_codes_array(input_format, &input_size);
    const char** output_codes = get_codes_array(output_format, &output_size);
    
    if (input_codes == NULL || output_codes == NULL) {
        printf("Invalid format(s) provided.\n");
        return 1;
    }
    
    int index = find_index(input_code, input_codes, input_size);
    
    if (index == -1) {
        printf("The binary code %s is not valid in the %s format.\n", input_code, input_format);
    } else {
        printf("The binary code %s in the %s format is %s in the %s format.\n", input_code, input_format, output_codes[index], output_format);
    }
    
    return 0;
}
