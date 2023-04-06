/*
    Write the binsearch function with only one test
    inside the loop (at the cost of more tests outside)
    measure the time difference between them
*/

#include <stdio.h>
#include <time.h>

int binsearch1(int target, int sorted_array[], int length);
int binsearch2(int target, int sorted_array[], int length);

int main(void)
{
    int target, subscript, msec;
    int sorted_array[26] = {
        2, 4, 5, 9, 10, 44, 66, 101, 102, 300, 333, 334, 400, 404, 500, 501, 502, 504, 505, 600, 601, 602, 604, 605, 606, 607
    };

    target = 600;
    clock_t start = clock(), diff;

    binsearch1(target, sorted_array, 26);
    msec = clock() - start;
    printf("Time taken for binary search function from book\n%d seconds %d milliseconds\n", msec/1000, msec%1000);

    start = clock(), diff;
    binsearch2(target, sorted_array, 26);
    printf("\n\nTime taken for binary search function modified\n%d seconds %d milliseconds\n", msec/1000, msec%1000);

    return 0;
}

int binsearch1(int target, int sorted_array[], int length)
{
    int low, mid, high;

    low = 0;
    high = length - 1;
    
    while (low <= high)
    {
        mid = (high + low) / 2;

        if (target < sorted_array[mid])
            high = mid - 1;
        else if (target > sorted_array[mid])
            low = mid + 1;
        else
            return mid;
    }

    return - 1;
}



int binsearch2(int target, int sorted_array[], int length)
{
    int low, mid, high;

    low = 0;
    high = length - 1;
    mid = (low + high) / 2;

    while (low <= high && sorted_array[mid] != target)
    {
        if (target > sorted_array[mid])
            low = mid + 1;
        else 
            high = mid - 1;

        mid = (low + high) / 2;
    }

    if (sorted_array[mid] == target)
        return mid;
    
    return -1;
}