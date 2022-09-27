#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count = 0;

int path(char[8][8], int, int, int, int*, int*);
void printf_maze(char[8][8]);

int main(void)
{
	char maze[8][8] = { {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
						{' ', 'X', 'X', ' ', 'X', ' ', 'X', ' '},
						{' ', ' ', 'X', ' ', 'X', 'X', ' ', ' '},
						{' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X'},
						{' ', ' ', ' ', ' ', 'X', 'X', ' ', 'X'},
						{'X', ' ', 'X', ' ', 'X', ' ', ' ', ' '},
						{' ', ' ', ' ', ' ', 'X', 'X', 'X', ' '},
						{' ', 'X', 'X', ' ', ' ', ' ', ' ', ' '} };
	int start_x = 0, start_y = 1;
	int check;
	int location_x[64], location_y[64];

	//printf("Maze: \n");
	//printf_maze(maze);
	check = path(maze, start_x, start_y, 0, location_x, location_y);

	if (check == 0) 
	{
		printf("There is no path to exit now, only %d paths to leave.", count);
	}

	printf("\n");
	system("pause");
	return 0;
}

int path(char maze[8][8], int x, int y, int location_count, int* location_x, int* location_y) 
{
	int succeed = 0;
	int i;

	maze[x][y] = '1';
	location_x[location_count] = x;
	location_y[location_count] = y;
	location_count++;
	//printf("(%d %d)\n", location_x[location_count], location_y[location_count]);
	
	if (x == 7 && y == 7) 
	{
		succeed = 1;
		count++;
		printf("The maze has paths to go!\nThis is the %dth path: \n\n", count);
		
		for (i = 0; i < location_count; i++) 
		{
			printf("(%d, %d)\n", location_x[i], location_y[i]);
		}

		printf("\n");
		//printf_maze(maze);
		maze[x][y] = ' ';
		return(succeed);
	}
	
	if (x <= 6 && maze[x + 1][y] == ' ')
	{
		path(maze, x + 1, y, location_count, location_x, location_y);
	}
	if (y <= 6 && maze[x][y + 1] == ' ')
	{
		path(maze, x, y + 1, location_count, location_x, location_y);
	}
	if (x >= 1 && maze[x - 1][y] == ' ')
	{
		path(maze, x - 1, y, location_count, location_x, location_y);
	}
	if (y >= 1 && maze[x][y - 1] == ' ')
	{
		path(maze, x, y - 1, location_count, location_x, location_y);
	}

	location_count--;
	maze[x][y] = ' ';

	return(succeed);
}

void printf_maze(char maze[8][8]) 
{
	int x, y;

	for (x = 0; x < 8; x++) 
	{
		for (y = 0; y < 8; y++)
		{
			printf("%c", maze[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}