#define _CRT_SECURE_NO_WARNINGS //先char進來123 轉成int - '0' 顛倒印刷321 判斷%9=0
#include <stdio.h>
#include <math.h>

int main(void) {
	char n;
	char input_char;
	int number, numberOpposite, sum, sumOpposite, i;
	printf("Enter the number: ");
	scanf("%c", &n);

	sum = 0;
	sumOpposite = 0;
	i = -1;

	while (n != '\n') {
			//printf("\n%c", n);
		i = i + 1;
		number = (int)n - (int)'0';
		sum = sum + number;
		numberOpposite = number * pow(10 , i);
			//printf("\n%d", sum);
		scanf("%c", &n);
		sumOpposite = sumOpposite + numberOpposite;
			//printf("\nopposite>> \n%d\nsum>> \n%d", numberOpposite, sumOpposite);
		}
	printf("The opposite number is %d", sumOpposite);
	if ((sum % 9) == 0) {
		printf("\nThe sum is %d and it is divisible by 9", sum);
	}
	else {
		printf("\nThe sum is %d and it is indivisible by 9", sum);
	}
	return 0;
}