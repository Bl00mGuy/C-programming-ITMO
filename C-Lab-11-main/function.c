#include "square.h"
#include <math.h>

double Perimeter(struct Square kvadrat){
return pow(kvadrat.x2 - kvadrat.x1,2) + pow(kvadrat.y2 - kvadrat.y1,2);
}

double Square(struct Square kvadrat){
return 4*sqrt(pow(kvadrat.x2 - kvadrat.x1,2) + pow(kvadrat.y2 - kvadrat.y1,2));
}
