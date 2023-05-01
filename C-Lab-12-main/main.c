#include <stdio.h>

int main() {
FILE *file = fopen("C:\\Users\\DESKTOP\\Desktop\\BrAVE\\12laba\\12lab.txt", "r");
char s[100];
while (!feof(file)){
fgets(s, 100, file);
fgets(s, 100, file);
puts(s);
}
 
fclose(file);
return 0;
