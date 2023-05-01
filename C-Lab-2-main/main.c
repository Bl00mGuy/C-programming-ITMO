#include <stdio.h>
#define _USE_MATH_DEFINES //mathematical constants
#include <math.h>

int main() {
    double ugol_a, z1, z2;
    printf("Enter the angle degree: \n");
    scanf("%lf", &ugol_a); //set the alpha value
    z1 = 1 - 1.0/4 * (pow(sin(2 * ugol_a),2)) + cos(2 * ugol_a);
    z2 = (pow(cos(ugol_a),2)) + (pow(cos(ugol_a),4));
    printf("Output:\n");
    printf("z1 = %.4f\n", z1);
    printf("z2 = %.4f", z2);
    return 0;
}
