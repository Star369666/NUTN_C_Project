#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void GetAnswer(int Mins, float Secs);
	
int main(void) {
	GetAnswer(3, 52.83);
	GetAnswer(3, 59.83);
	GetAnswer(4, 00.03);
	GetAnswer(4, 16.22);
	return 0;
}

void GetAnswer(int Mins, float Secs) {
	float OneMile;
	float meter;
	float feet;
	float FPS;
	float MPS;

	OneMile = 1;
	feet = OneMile * 5280;
	meter = (feet / 3282) * 1000;

	FPS = feet / (60 * Mins + Secs);
	MPS = meter / (60 * Mins + Secs);
	printf("\nThe star's data:\nTime: %dminutes and %.2fseconds\nFPS: %.f\nMPS: %.2f\n", Mins, Secs, FPS, MPS);
}
