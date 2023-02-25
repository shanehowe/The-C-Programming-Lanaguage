#include <stdio.h>

/* print Fahrenheit -> Celsius table
 * for fahr = 0, 20, ... , 300
*/

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    // Print the table header
    printf("------------------------------\n");
    printf("| Fahrenheit to Celsius table |\n");
    printf("------------------------------\n");
    fahr = lower;
    while(fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%6s %3.0f ->%6.1f\n", " ", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}