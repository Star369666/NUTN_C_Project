#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	float hour;
	float minute;
	float TotalTime;
	float temperture;
	printf("Enter the total power failture time, hour and minute: ");
	scanf("%f %f", &hour, &minute);
	TotalTime = hour + minute / 60;
	temperture = (4 * TotalTime * TotalTime) / (TotalTime + 2) - 20;
	printf("The finally temperture is %.1f.", temperture);
	return 0;
}