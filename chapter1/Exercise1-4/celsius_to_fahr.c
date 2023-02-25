#include <stdio.h>

int main()
{
    int celsius;
    float fahr;

    for (celsius = 0; celsius <= 300; celsius = celsius + 20)
    {
        fahr = (celsius * (9.0 / 5.0)) + 32;
        printf("%3d %6.1f\n", celsius, fahr);
    }

    return 0;
}