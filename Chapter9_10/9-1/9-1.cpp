#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int blob_check(int[5][5], int, int);
void printf_array(int[5][5]);

int main(void) 
{
	int x, y;
	int grid[5][5] = { {0, 1, 0, 1, 1},
					   {1, 0, 0, 0, 1},
					   {0, 0, 1, 0, 1},
					   {0, 1, 1, 0, 0},
					   {1, 1, 0, 0, 0} };
	int answer, temp;

	printf("Enter the location (x, y): ");
	scanf("%d %d", &x, &y);

	temp = x;
	x = y;
	y = temp;
	answer = blob_check(grid, x, y);

	if (answer == 0)
	{
		printf("The cell (x, y) may not be on the grid, or the cell (x, y) may be empty.\n");
	}
	else 
	{
		printf("There are %d pixels in the blob\n", answer);
	}
	
	printf("\n");
	system("pause");
	return 0;
}

int blob_check(int location[5][5], int x, int y) 
{
	int area = 0;
	int i, j;

	if (x < 0 || x > 4 || y < 0 || y > 4) 
	{
		area = 0;
		return (area);
	}
	else if (location[x][y] == 0)
	{
		area = 0;
		return (area);
	}
	else if(location[x][y] == 1)
	{
		location[x][y] = -1;
		area += 1;
		//printf_array(location);
		area = area + blob_check(location, x - 1, y + 1) 
					+ blob_check(location, x, y + 1) 
					+ blob_check(location, x + 1, y + 1) 
					+ blob_check(location, x - 1, y) 
					+ blob_check(location, x, y) 
					+ blob_check(location, x + 1, y) 
					+ blob_check(location, x - 1, y - 1) 
					+ blob_check(location, x, y - 1) 
					+ blob_check(location, x + 1, y - 1);
		return(area);
	}
	else
	{
		return(area);
	}
}

void printf_array(int grid[5][5])
{
	int i, j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++) 
		{
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}