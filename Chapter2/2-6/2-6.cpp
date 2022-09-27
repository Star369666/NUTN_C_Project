#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char DesiredGrade;
	float MinimumAverage;
	float CurrentAverage;
	float ThePercentage;
	float NeededScore;
	printf("Enter desired grade> ");
	scanf(" %c", &DesiredGrade);
	printf("Enter minimum average required> ");
	scanf(" %f", &MinimumAverage);
	printf("Enter current average in course> ");
	scanf(" %f", &CurrentAverage);
	printf("Enter how much the final counts as a percentage of the course grade> ");
	scanf(" %f", &ThePercentage);
	NeededScore = (MinimumAverage - CurrentAverage * 0.75) / 0.25;
	printf("You need a score of %.2f on the final to get a %c.", NeededScore, DesiredGrade);

	return 0;
}