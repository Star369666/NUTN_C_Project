#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    float beginning;
    float ending;
    float distance;
    float total;
    printf("TAXI FARE CALCULAYOT");
    printf("\nEnter beginning odometer reading=> ");
    scanf("%f", &beginning);
    printf("Enter ending odometer reading=> ");
    scanf("%f", &ending);
    distance = (ending - beginning);
    total = distance * 1.50;
    printf("You traveled a distance of %1.1f miles. At $1.50 per mile, your fare is $%.2f.", distance, total);
    return 0;
}