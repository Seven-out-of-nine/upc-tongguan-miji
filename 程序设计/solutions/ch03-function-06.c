#include <stdio.h>
#include <math.h>

double fun(double a)
{
    double shifted = a * 100.0 + 0.5;
    return floor(nextafter(shifted, HUGE_VAL)) / 100.0;
}

int main( )
{   double  a;
    scanf ( "%lf", &a );
    printf ( "%lf\n", fun ( a ) );
    return 0;
}
