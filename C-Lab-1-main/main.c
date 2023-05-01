#include <stdio.h>

int main() {
    int number;
    char string[666];
    printf("Enter the string: \n");
    gets(string);
    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("Output: \n");
    puts(string);
    printf("%d", number);
    return 0;
}