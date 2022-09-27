#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binary_srch(int[40], int, int, int*);

int main(void)
{
    int input_number[40];
    int i, input_max, search;
    int found;
    int location;

    printf("Enter how much elements are input: ");
    scanf("%d", &input_max);
    printf("Enter all the datas: ");

    for (i = 0; i < input_max; i++)
    {
        scanf(" %d", &input_number[i]);
        //printf(" %d ", input_number[i]);
    }

    printf("Enter the data for search: ");
    scanf("%d", &search);

    /* -333 -33 -1 0 5 5 11 47 101 789 */
    
    found = binary_srch(input_number, input_max, search, &location);
    
    if (found == 0)
    {
        printf("The value is not in the array\n");
    }
    else
    {
        printf("The value %d is in location %dth\n", search, location);
    }

    system("Pause");
    return 0;
}

int binary_srch(int input_number[], int max, int search, int* location)
{
    int top, bottom, middle;
    
    bottom = 0;
    top = max - 1;
    middle = (bottom + top) / 2;

    while (input_number[middle] != search)
    {
        if (input_number[middle] > search)
        {
            top = middle - 1;
        }
        else if (input_number[middle] < search)
        {
            bottom = middle + 1;
        }
        middle = (top + bottom) / 2;
        if (bottom > top) 
        {
            return 0;
        }
    }
    
    *location = middle;
    
    return 1;
}