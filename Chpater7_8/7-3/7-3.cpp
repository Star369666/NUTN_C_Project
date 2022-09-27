#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define row 11
#define column 3

void fget_point_mass(FILE*, int*, int[row][column], int[row]);
void center_grav(int, int[row][column], int[row], int[row], int[row], int[row]);
void fwrite_point_mass(FILE*, int, int[row][column], int[row]);

int main(void)
{
	FILE* inp;
	FILE* outp;
	inp = fopen("input.txt", "r");
	outp = fopen("output.txt", "w");

	int location[row][column];
	int mass[row];
	int n;
	int x[row], y[row], z[row];
	
	fget_point_mass(inp, &n, location, mass);
	center_grav(n, location, mass, x, y, z);
	fwrite_point_mass(outp, n, location, mass);

	system("pause");
	return 0;
}

void fget_point_mass(FILE* inp, int* n, int location[row][column], int mass[row])
{
	int row_for_change, column_for_change;
	int n_maximum, i;

	fscanf(inp, " %d", &n_maximum);

	for (row_for_change = 0; row_for_change < n_maximum; row_for_change++)
	{
		//printf("\nlocation\n");
		for (column_for_change = 0; column_for_change < column; column_for_change++)
		{
			fscanf(inp, " %d", &location[row_for_change][column_for_change]);
			//printf("%d  ", matrix[row_for_change][column_for_change]);
		}
		fscanf(inp, " %d", &mass[row_for_change]);
		//printf("\nmass\n%d", scalar[row_for_change]);
	}
	
	*n = n_maximum;

	/* Printf location */
	printf("location\n");
	
	for (column_for_change = 0; column_for_change < column; column_for_change++)
	{
		printf(" %10d ", location[0][column_for_change]);
	}
	printf("\n");
	for (column_for_change = 0; column_for_change < column; column_for_change++)
	{
		printf("  %9d ", location[1][column_for_change]);
	}
	printf("\n");
	for (column_for_change = 0; column_for_change < column; column_for_change++)
	{
		printf(" %10d ", location[2][column_for_change]);
	}
	printf("\n");
	for (column_for_change = 0; column_for_change < column; column_for_change++)
	{
		printf(" %10d ", location[3][column_for_change]);
	}
	printf("\n");

	/* Printf mass */
	printf("mass \n");

	for (i = 0; i < 4; i++) 
	{
		printf(" %10d \n", mass[i]);
	}

	/* Printf n */
	printf("n\n %10d\n", row_for_change);
}

void center_grav(int n, int matrix[row][column], int mass[row], int x[row], int y[row], int z[row])
{
	int row_change, column_change;
	float gX = 0, gY = 0, gZ = 0, sum_mass = 0;
	float gx, gy, gz;

	for (row_change = 0; row_change < n; row_change++)
	{
		x[row_change] = matrix[row_change][0];
		gX = gX + (mass[row_change]) * (x[row_change]);
	}
	for (row_change = 0; row_change < n; row_change++)
	{
		y[row_change] = matrix[row_change][1];
		gY = gY + mass[row_change] * y[row_change];
	}
	for (row_change = 0; row_change < n; row_change++)
	{
		z[row_change] = matrix[row_change][2];
		gZ = gZ + mass[row_change] * z[row_change];
	}
	
	for (row_change = 0; row_change < n; row_change++) 
	{
		sum_mass = sum_mass + mass[row_change];
	}

	gx = gX / sum_mass;
	gy = gY / sum_mass;
	gz = gZ / sum_mass;
	printf("\nThe location at the center of gravity is (%.3f, %.3f, %.3f)\n\n", gx, gy, gz);
}

void fwrite_point_mass(FILE* outp, int n, int location[row][column], int mass[row])
{
	int row_change, column_change;
	int mass_change;

	fprintf(outp, "location\n");

	for (row_change = 0; row_change < n; row_change++)
	{
		for (column_change = 0; column_change < column; column_change++)
		{
			fprintf(outp, " %9d", location[row_change][column_change]);
		}
		fprintf(outp, "\n");
	}

	fprintf(outp, "mass\n");
	
	for (mass_change = 0; mass_change < n; mass_change++)
	{
		fprintf(outp, "%10d", mass[mass_change]);
		fprintf(outp, "\n");
	}

	fprintf(outp, "n\n%10d", n);
}