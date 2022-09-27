#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

float f_of_X(float, float, float);
float f_of_X_derivative(float, float);

int main(void) {
	float x0;
	float y1;
	int times;
	float c;
	
	printf("Enter the initial guess (= c/2): ");
	scanf("%f", &c);
	printf("Enter how many times sqrting: ");
	scanf("%d", &times);
	
	x0 = c / 2;
	y1 = f_of_X(x0, c, times);
	
	do {
		x0 = x0 - f_of_X(x0, c, times) / f_of_X_derivative(x0, times);
		y1 = f_of_X(x0, c, times);
	}	while (fabs(y1) - 0 >= pow(10, -6));
	printf("The root is %f", x0);
	return 0;
}

float f_of_X_derivative(float x0, float times) {

	return (times * pow(x0, times - 1));
}
float f_of_X(float x0, float c, float times) {

	return (pow(x0, times) - c);
}