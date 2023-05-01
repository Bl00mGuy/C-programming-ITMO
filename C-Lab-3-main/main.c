#include <stdio.h>

int main() {
    int first, second;
    printf("Enter your favorite number in DEC number system: \n");
    scanf("%d", &first);
    printf("Your favorite number in HEX number system: \n");
    printf("%x\n", first);
    printf("Your favorite number in DEC number system, and it is also shifted to 1 bit to the right: \n");
    printf("%d, %d\n", first, first >> 1);
    int anti_first = ~first;
    printf("Your favorite number in OCT number system, and it is the same with\n"
           "the bitwise negation operation applied to it: \n");
    printf("%o, %o\n", first, anti_first);
    printf("Enter your second favorite number in the OCT number system: \n");
    scanf("%o", &second);
    printf("The result of the bitwise \"exclusive or\" operation with the numbers you entered: \n");
    printf("%o", first^second);
    return 0;
}
