#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

float g(float);
float h(float);
float trap(float, float, int, char);

int main(void) {
	char function;
	int n;
	float area1;

	printf("Enter 'g' or 'h' to choice which function to use: ");
	scanf("%c", &function);

	switch (function) {
	case'G':
	case'g':
		for (n = 2; n <= 128; n = 2 * n) {
			area1 = trap(0, 3.14159, n, function);
			printf("\nn = %d\narea = %f\n\n", n,area1);
		}
		break;
	case'H':
	case'h':
		for (n = 2; n <= 128; n = 2 * n) {
			area1 = trap(-2, 2, n, function);
			printf("\nn = %d\narea = %f\n\n", n, area1);
		}
		break;
	default:
		break;
	}
	
	return 0;
}

float gFunction(float gX) {
	return (pow(gX, 2) * sin(gX));
}
float hFunction(float hX) {
	return (sqrt(4 - pow(hX, 2)));
}

float trap(float a, float b, int n, char function) {
	float length;
	int i = 1;
	float area, area1;
	float sigma;

	sigma = 0;
	
	/*for (n = 2; n <= 128; n = 2 * n) {
		area1 = trap(0, 3.14159, n, function);
		printf("n = %d\narea = %f\n\n", n, area1);
	}*/

	length = (b - a) / n;
	
	switch (function) {
	case'G':
	case'g':
		for (i = 1; i < n; i++) {
			sigma = sigma + 2 * gFunction(a +  i * length);
		}
		area = length / 2 * (gFunction(a) + gFunction(b) + sigma);
		break;
	case'H':
	case'h':
		for (i = 1; i < n; i++) {
			sigma = sigma + 2 * hFunction(a + i * length);
		}
		area = length / 2 * (hFunction(a) + hFunction(b) + sigma);
		break;
	default:
		break;
	}
	return (area);
}
	
	

