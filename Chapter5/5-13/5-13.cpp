#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *inp;
	inp = fopen("input.txt", "r");
	int PlayNumber;
	float Num1 = 0;
	float Num2 = 0;
	char PlayerRecord;
	float average;
	

	while (fscanf(inp, "%d", &PlayNumber) != EOF) {
		printf("Player %d's record:", PlayNumber);
		Num1 = 0;
		Num2 = 0;
		while (fscanf(inp, "%c", &PlayerRecord) != EOF && PlayerRecord != '\n') {
			printf("%c", PlayerRecord);
			switch (PlayerRecord) {
			case 'O':
				Num2 = Num2 + 1;
				break;
			case 'H':
				Num1 = Num1 + 1;
				break;
			case '\n':
				break;
			default:
				break;
			}
		}
		average = Num1 / (Num1 + Num2);
		printf("\nPlayer %d's batting average: %.3f \n\n", PlayNumber, average);
	}
	fclose(inp);
}