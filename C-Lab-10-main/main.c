#include <stdio.h>
#include <math.h>

int NOD (int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    int result = a + b;
    return result;
}

void sum(int number, int *pointer){
    *pointer = *pointer + number % 10;
    if (number / 10 != 0){
        sum(number/10, pointer);
    }
}

int NOK (int a, int b) {
    int result = a / NOD(a, b) * b;
    return result;
}

int main() {
    printf("#Task 1#\n");
    int a,b;

    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("\n");
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("\n");

    int naib_obsh_del = NOD(a, b);
    printf("NOD of entered numbers: %d\n", naib_obsh_del);

    int naib_obsh_krat = NOK(a, b);
    printf("NOK of entered numbers: %d\n", naib_obsh_krat);
    printf("\n");

    printf("#Task 4#\n");
    int number;
    int k = 0;
    printf("Enter the number: ");
    scanf("%d", &number);
    sum(number, &k);
    printf("%d", k);

    return 0;
}
