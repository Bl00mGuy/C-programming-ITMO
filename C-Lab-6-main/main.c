#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Task 1:\n");
    char m[4] = {'W','O','R','K'};
    char *pm = m;
    printf("%c %c \n%c %c\n", *pm,  *(pm+1), *(pm+2), *(pm+3));
    printf("Task 2:\n");
    char *m2 = (char*)malloc(4 * sizeof(char));
    char *pm2 = m2;
    *(pm2) = 'W';
    *(pm2+1) = 'O';
    *(pm2+2) = 'R';
    *(pm2+3) = 'K';
    for (int i = 0; i < 4; ++i) {
        printf("%c\n", *(pm2+i));
    }
    free (m2);
    return 0;
}
