#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
	int number;
	int number1;
	int i;
	int sum;

	printf("Enter the number: ");
	scanf("%d", &number);
	i = -1;
	sum = 0;
	printf("The opposite number is ");

	while ((int(number / pow(10, i))) >= 10) {
		i = i + 1;
		number1 = (int(number / pow(10, i))) % 10;
		printf("%d", number1);
			//printf("\n%d\n", int(number / pow(10, i)));
		sum = sum + number1;
	}

	if ((sum % 9)  == 0) {
		printf("\nThe sum %d is divisible by 9", sum);
	}
	else {
		printf("\nThe sum %d is indivisible by 9", sum);
	}

	return 0;
}