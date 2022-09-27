#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int volume;
	int minute;
	int rate;
	printf("Volume to be infused=> ");
	scanf(" %d", &volume);
	printf("Minute over which to infuse=> ");
	scanf(" %d", &minute);
	rate = volume * 60 / minute;
	printf("\nVTBI: %d ml", volume);
	printf("\nRate: %d ml/hr", rate);
	return 0;
}