#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int search(char[10][7], int*, char[40]);

int main(void)
{
	char color_code[10][7] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white" };
	char band1[40], band2[40], band3[40];
	int first_location, second_location, third_location;
	float result;
	int first, second, third;
	char choose, buffer_cleaner;
	int error = 0;

	do
	{
		printf("Enter the colors of the resistor's three bands, beginning with the band nearest the end.\nType the colors in lowercase letters only, NO CAPS.\n");
		printf("Band 1 => ");
		scanf("%s", &band1);
		printf("Band 2 => ");
		scanf("%s", &band2);
		printf("Band 3 => ");
		scanf("%s", &band3);

		if (search(color_code, &first_location, band1) == 0)
		{
			first = (10 * first_location);
		}
		else
		{
			printf("Invalid color: %s\n", band1);
			error = 1;
		}
		if (search(color_code, &second_location, band2) == 0)
		{
			second = second_location;
		}
		else
		{
			printf("Invalid color: %s\n", band2);
			error = 1;
		}
		if (search(color_code, &third_location, band3) == 0)
		{
			third = pow(10, third_location);
		}
		else
		{
			printf("Invalid color: %s\n", band3);
			error = 1;
		}
		//printf("\nfirst=%d, second=%d, third=%d", first, second, third);
		if (error != 1) 
		{
			result = ((first + second) * third) / 1000.0;

			printf("Resistance value: %.2f kilo-ohms\n", result);
		}
		do 
		{
			scanf("%c", &buffer_cleaner);
		} while (buffer_cleaner != '\n');
		
		error = 0;
		printf("Do you want to decode another resistor?(enter y for do again and n for quit)\n>>");
		scanf("%c", &choose);
		printf("\n");

	} while (choose == 'y' && error != 1);
	system("Pause");
	return 0;
}

int search(char color_code[10][7], int* location, char band[40])
{
	int i, result[10];
	int check = 0;

	for (i = 0; i < 10; i++)
	{
		result[i] = strcmp(band, color_code[i]);
		if ((result[i]) == 0) 
		{
			*location = i;
			check = 0;
			return(check);
			printf("i == = %d", i);
		}
		else if ((result[i]) != 0) 
		{
			check = -1;
		}
		//printf("\ni=%d\nband=%s\ncolorcode=%s\ncheck=%d\n", i, band, color_code[i], check);
	}
	return(check);
}