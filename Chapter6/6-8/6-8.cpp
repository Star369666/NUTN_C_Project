#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void average_cost(float, float*);
float round_money(float, float);

int main(void) 
{
	FILE* inp;
	FILE* outp;
	inp = fopen("usage.txt", "r");
	outp = fopen("charges.txt", "w");

	int month;
	int year;
	int custom_number;
	float hours_for_use;
	float per_hour_cost;

	fscanf(inp, "%d %d", &month, &year);
	fprintf(outp, "Charges for %d/%d\n", month, year);
	fprintf(outp, "					 Charge");
	fprintf(outp, "\nCustom		Hours used		per hour		Average cost");

	
	while (fscanf(inp, "%d %f", &custom_number, &hours_for_use) != EOF && custom_number != ' ' && custom_number != '\n' && hours_for_use != ' ' && hours_for_use != '\n')
	{
		fprintf(outp, "\n%d		  %.1f", custom_number, hours_for_use);
		average_cost(hours_for_use, &per_hour_cost);
		fprintf(outp, "			 %.2f", per_hour_cost);
		fprintf(outp, "			   %.2f", round_money(hours_for_use, per_hour_cost));
	}

	system("pause");
	return 0;
}

void average_cost(float hour, float* hour_cost)
{
	if (hour <= 10) 
	{
		*hour_cost = 7.99;
	}
	else if (hour > 10) 
	{
		*hour_cost = 7.99 + ceil(hour - 10) * 1.99;
	}
}

float round_money(float hour, float hour_cost)
{
	float average_cost;

	average_cost = hour_cost / hour;
	average_cost = int(average_cost * 100 + 0.5) / 100.0;

	return (average_cost);
}