#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define water 100
#define mercury 357
#define copper 1187
#define sliver 2193
#define gold 2660

int within_x_percent(int ref, float BoilPoint, float percent) {
	float refLeft;
	float refRight;

	refLeft = ref * (1 - percent/100);
	refRight = ref * (1 + percent/100);

	if (refLeft <= BoilPoint && BoilPoint <= refRight) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(void) {
	float BoilPoint;
	float percent;

	printf("\nEnter a data value data: ");
	scanf("%f", &BoilPoint);
	printf("\nEnter a percentage value: ");
	scanf("%f", &percent);
	

	if (within_x_percent(water, BoilPoint, percent)) {
		printf("Water");
	}
	else if (within_x_percent(mercury, BoilPoint, percent)) {
		printf("Mercury");
	}
	else if (within_x_percent(copper, BoilPoint, percent)) {
		printf("Copper");
	}
	else if (within_x_percent(sliver, BoilPoint, percent)) {
		printf("Sliver");
	}
	else if (within_x_percent(gold, BoilPoint, percent)) {
		printf("Gold");
	}
	else {
		printf("Substance unknown");
	}

	return 0;
}