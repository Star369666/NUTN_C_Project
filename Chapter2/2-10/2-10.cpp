#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	float x1, y1;
	float x2, y2;
	float midx, midy;
	float OriginalSlope;
	float MidlineSlope;
	float TheB;
	printf("Enter the first point: ");
	scanf("%f %f", &x1, &y1);
	printf("Enter the second point: ");
	scanf("%f %f", &x2, &y2);
	
	midx = (x1 + x2) / 2;
	midy = (y1 + y2) / 2;
	OriginalSlope = (y2 - y1) / (x2 - x1);
	MidlineSlope = -1 / OriginalSlope;
	TheB = midy - MidlineSlope * midx;
	
	printf("The slope between two points' is %.2f", OriginalSlope);
	printf("\nThe middle point is [%.2f,%.2f]", midx, midy);
	printf("\nThe slope of the perpendicular bisector is %.2f", MidlineSlope);
	printf("\nThe y-intercept is %.2f", TheB);
	printf("\nWith the coordinates of points [%.2f,%.2f] and [%.2f,%.2f], the format is y = %.2fx + %.2f", x1, y1, x2, y2, MidlineSlope, TheB);
	printf("\nIt might be fail if you do following descriptions:\n1. Typing too many characters in [x1,y1] or [x2, y2] causing them over the limit.\n2. Typing words which are not char or typing number with symbols");
	return 0;
}