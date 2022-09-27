#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
	float mass;
	float high;
	float bmi;
	float finalBMI;

	printf("Enter the weight(pounds): ");
	scanf("%f", &mass);
	printf("\nEnter the height(inches): ");
	scanf("%f", &high);
	
	bmi = 703 * mass / pow(high, 2);
	finalBMI = int(bmi * 10.0 + 0.5);
	finalBMI = finalBMI / 10.0;

	if (finalBMI < 18.5) {
		printf("\nUnderweight");
	}
	else if (18.5 <= finalBMI && finalBMI <= 24.9) {
		printf("\nNormal");
	}
	else if (25.0 <= finalBMI && finalBMI <= 29.9) {
		printf("\nOverweight");
	}
	else if (30 <= finalBMI) {
		printf("\nObese");
	}

	printf("\nThe BMI is %.1f", finalBMI);

	return 0;
}