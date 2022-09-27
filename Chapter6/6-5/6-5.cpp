#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inverseAndInteger(char, int*,int*);
int primeCheck(int);
int palindromeCheck(int, int);

int main(void)
{
	char inputNumber;
	int integerNumber;
	int inversedNumber;
	
	printf("Number: ");

	while (scanf("%c", &inputNumber) != EOF && inputNumber != '\n' && inputNumber != ' ')
	{
		//inputPointer = &inputNumber;
		//*inputPointer = inputNumber;
			
		inverseAndInteger(inputNumber, &inversedNumber, &integerNumber);

		if (primeCheck(integerNumber) == 0)
		{
			printf("\nThe number is prime.");
		}
		else
		{
			printf("\nThe number is not prime.");
		}

		if (palindromeCheck(integerNumber, inversedNumber) == 0)
		{
			printf("\nThe number is palindrome.");
		}
		else
		{
			printf("\nThe number is not palindrome.");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

void inverseAndInteger(char num, int* inversedNumber,int* integerNum)
{
	int times = 0;
	int intCondition = 0;
	int TheInteger = 0;

	while (num != EOF && num != '\n' && num != ' ')
	{
		intCondition = intCondition * 10 + (num - '0');
		times = times + 1;
		scanf("%c", &num);
	}
	*integerNum = intCondition;
	//printf("\n\n%d\n\n", count);
	for (int i = times; i >= 0; i--)
	{
		int rest = intCondition % 10;
		intCondition = intCondition / 10;
		TheInteger = TheInteger + rest * pow(10, i-1);
	}
	*inversedNumber = TheInteger;
	printf("\nThe opposite number is %d", TheInteger);
}

int primeCheck(int integerNum)
{
	if (integerNum == 1)
	{
		return 0;
	}
	for (int i = 2; i <= sqrt(integerNum); i = i + 1)
	{
		if (integerNum % i == 0)
		{
			printf("i= %d", i);
			return 1;
		}
	}
	return 0;
}
int palindromeCheck(int intergerNum, int inversedNumber) {
	if (intergerNum == inversedNumber) 
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}