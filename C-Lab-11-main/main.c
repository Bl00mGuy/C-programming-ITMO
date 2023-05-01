#include <stdio.h>
#include "square.h"

int main() {
struct Square kvadrat;
printf("Enter the coordinates of the first point: ");
scanf("%lf %lf", &kvadrat.x1, &kvadrat.y1);
printf("\n");
printf("Enter the coordinates of the second point: ");
scanf("%lf %lf", &kvadrat.x2, &kvadrat.y2);
printf("\n");
printf("Perimeter = %.2lf \n", Perimeter(kvadrat));
printf("Square = %.2lf \n", Square(kvadrat));
return 0;
}
