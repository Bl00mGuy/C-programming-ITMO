#include <stdio.h>

int main() {
    int number1, number2;
    int pervoe = -3;
    int poslednee = 6;
    printf("Enter the first number: \n");
    scanf("%d", &number1);
    printf("The result of checking your number for hitting the interval [-3;6] (in/out): \n");
    if (number1 >= pervoe && number1 <= poslednee){
        printf("In the range\n");
    }
    else {
        printf("Out of range\n");
    }
    printf("Enter the second number: \n");
    scanf("%d", &number2);
    printf("The result of checking: \n");
    printf("%d", (number2 >> 4) % 2);
    return 0;
}
