#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	float amount;
	
	printf("Enter the amount of data used by the subscriber: ");
	scanf("%f", &amount);

	if (0.0 < amount && amount <= 1.0) {
		printf("Charges: 250");
	}
	else if (1.0 < amount && amount <= 2.0) {
		printf("Charges: 500");
	}
	else if (2.0 < amount && amount <= 5.0) {
		printf("Charges: 1000");
	}
	else if (5.0 < amount && amount <= 10.0) {
		printf("Charges: 1500");
	}
	else if (10 < amount) {
		printf("Charges: 2000");
	}
	else {
		printf("The charge is a bad data.");
	}
	return 0;
}