#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	int UPC[12];
	int i;
	int even_sum = 0, odd_sum = 0;
	int triple_even;
	int check_num, check_number;

	printf("Enter the UPC with 12-digit using by push space to divide: ");

	for (i = 0; i < 12; i++) 
	{
		scanf("%d", &UPC[i]);
	}

	for (i = 0; i < 12; i = i + 2) 
	{
		even_sum = even_sum + UPC[i];
	}

	triple_even = 3 * even_sum;

	for (i = 1; i < 11; i = i + 2) 
	{
		odd_sum = odd_sum + UPC[i];
	}

	check_num = triple_even + odd_sum;

	if ((check_num % 10) == 0) 
	{
		check_number = 0;
	}
	else 
	{
		check_number = 10 - (check_num % 10);
	}

	printf("The result of step 1 is %d\n", triple_even);
	printf("The result of step 2 is %d\n", odd_sum);

	if (check_number == UPC[11]) 
	{
		printf("Vlidated\n\n");
	}
	else 
	{
		printf("Error in barcode\n\n");
	}

	system("pause");
	return 0;
}