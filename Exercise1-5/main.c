#include <stdio.h>

/* Fahrenheit - Celcius in reverse order */
int main()
{
    int fahr;
    
    // Print the table header
    printf("------------------------------\n");
    printf("| Fahrenheit to Celsius table |\n");
    printf("------------------------------\n");

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%8s %3d %6.1f\n", " ", fahr, (5.0 / 9.0) * (fahr - 32));

    return 0;
}