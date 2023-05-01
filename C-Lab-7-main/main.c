#include <stdio.h>

enum Music {
    Classic, Pop, Rock, Rap, Punk, Indie, Metal, Folk
};
struct Straight {
    int length;
};
union Modem {
    int value;
    struct {
        unsigned char DSL: 1;
        unsigned char PPP: 1;
        unsigned char Link: 1;
    };
};
int main(){
    printf("#Task 1#\n");
    enum Music m = Rock;
    printf("%d\n", m);
    printf("#Task 2#\n");
    struct Straight line;
    printf("Enter straight length:");
    scanf("%d", &line.length);
    printf("Output:%d\n", line.length);
    printf("#Task 3#\n");
    union Modem o;
    printf("Enter the number in HEX: ");
    scanf("%x", &o.value);
    printf("DSL: %s /// PPP: %s /// Link: %s \n",
           o.DSL ? "ON" : "OFF",
           o.PPP ? "ON" : "OFF",
           o.Link ? "ON" : "OFF");
    return 0;
}
