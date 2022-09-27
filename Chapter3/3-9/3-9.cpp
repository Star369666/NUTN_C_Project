#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void getAnswer() {
	int day;
	int caseX;
	printf("FLU EPIDEMIC PREDICTIONS BASED ON ELAPSED DAYS SINCE FIRST CASE REPORT");
	printf("\n\nEnter day number>> ");
	scanf("%d", &day);
	caseX = 1 * (40000 / (1 + 39999 * exp(-0.24681 * day)));
	printf("By day %d, model predicts %d cases total.\n\n", day, caseX);
}

int main(void) {
	
	getAnswer();
	getAnswer();
	getAnswer();
	return 0;
}

