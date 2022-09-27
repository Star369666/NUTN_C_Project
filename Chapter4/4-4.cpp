#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	
	char ColorContent;
	printf("Enter the color(character): ");
	scanf("%c", &ColorContent);
	switch (ColorContent) {
		case ('O'):
		case ('o'):
			printf("orange	ammonia");
			break;
		case ('B'):
		case ('b'):
			printf("brown	carbon monoxide");
			break;
		case ('Y'):
		case ('y'):
			printf("yellow	hydrogen");
			break;
		case ('G'):
		case ('g'):
			printf("green	oxygen");
			break;
		default:
			printf("Contents unknown");
			break;
	}
	return 0;
}