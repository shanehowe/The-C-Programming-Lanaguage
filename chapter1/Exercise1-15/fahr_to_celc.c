#include <stdio.h>


float fahr_to_celsius(int fahr);

int main()
{
    int i, lower, upper, step;

    step = 20;
    upper = 300;
    lower = 0;

    for (i = lower; i <= upper; i += step)
        printf("%3d %6.2f\n", i, fahr_to_celsius(i));
    
    return 0;
}

float fahr_to_celsius(int fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}