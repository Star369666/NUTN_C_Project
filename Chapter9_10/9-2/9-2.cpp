#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void isclean(char[100], char*);
void become_lower(char[100], char*);
int palindrome(char[100], int, int);

int main(void) 
{
	/* 1. for input originally. 
	   2. for keep only english words and numbers. 
	   3. for let every english words become lower. */
	char input_string[100], input_string2[100], input_string3[100];
	int i;
	int check;

	printf("Enter a string to compare if it is a palindrome string: ");
	fgets(input_string, sizeof(input_string), stdin);
	//printf("%s\n\n", input_string);
	isclean(input_string, input_string2);
	//printf("%s\n\n", input_string2);
	become_lower(input_string2, input_string3);
	printf("\nThe transform string is -- %s\n\n", input_string3);
	
	check = palindrome(input_string3, 0, (strlen(input_string3) - 1));

	if (check == 1) 
	{
		printf("The return number is %d which means that it is a palindrome string\n", check);
	}
	else 
	{
		printf("The return number is %d which means that it is not a palindrome string\n", check);
	}

	printf("\n");
	system("pause");
	return 0;
}

void isclean(char input[100], char* take) 
{
	int i, j = 0, a = 0;

	for (i = 0; i < strlen(input); i++) 
	{
		if (isalnum(input[i]))
		{
			take[j] = input[i];
			j++;
		}
		else if(input[i] == '¡¦') 
		{
			a++;
		}
	}
	take[j] = '\0';
}

void become_lower(char input[100], char* take) 
{
	int i, j = 0;

	for (i = 0; i < strlen(input); i++) 
	{
		if (isalpha(input[i])) 
		{
			take[j] = tolower(input[i]);
			j++;
		}
		else if (isdigit(input[i])) 
		{
			take[j] = input[i];
			j++;
		}
	}
	take[j] = '\0';
}

int palindrome(char input[100], int start, int end) 
{
	int same = 1;

	if (same == 1)
	{
		if (start == end)
		{
			same = 1;
			return same;
		}
		else if(start == end - 1) 
		{
			if (input[start] == input[end]) 
			{
				same = 1;
				return same;
			}
			else 
			{
				same = 0;
				return same;
			}
		}
		else if (input[start] == input[end])
		{
			start += 1;
			end -= 1;
			same = palindrome(input, start, end);
			return same;
		}
		else 
		{
			same = 0;
			return same;
		}
	}
	else 
	{
		same = 0;
		return same;
	}
}