#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int find_min(int[5], int, int);
void sort(int[5]);

int main(void) 
{
	int i, small_number, location;
	int list[5] = {5, 4, 3, 2, 1};

	sort(list);
	printf("result= %d, %d, %d, %d, %d\n\n",list[0], list[1], list[2], list[3], list[4]);

	system("pause");
	return 0;
}

int find_min(int list[5], int start, int max) 
{
	int small_number, i, index;

	small_number = list[start];
	index = start;

	for (i = start; i < max; i++)
	{
		if (list[i] < small_number)
		{
			small_number = list[i];
			index = i;
		}
		printf("small is %d, i = %d\n", small_number, i);
	}
	return(index);
}

void sort(int list[5]) 
{
	int change, index_min, start = 0; 
	int max = 5;

	for (start = 0; start < max-1; ++start) 
	{
		index_min = find_min(list, start, max);

		if (start != index_min) 
		{
			change = list[index_min];
			list[index_min] = list[start];
			list[start] = change;
		}

		printf("i= %d, result= %d, %d, %d, %d, %d\n\n", start, list[0], list[1], list[2], list[3], list[4]);
	}
}