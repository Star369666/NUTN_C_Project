#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct 
{
	char language[21];
	int number_of_words;
	char words[12][21];
}word_list;

void load_word_list(char*, word_list*);
int add_word(word_list*, char*);
int contains(word_list*, char*);
int equal_lists(word_list*, word_list*);
void display_word_list(word_list*, word_list*);

int main(void)
{
	char file_name[21];
	char sencond_language[21], list2_word_buffer[21];
	char contain_input[21];
	word_list list1, list2;
	int i, check, check_first;
	int list2_array[80];
	int equal_array[12];

	/* Function1 - load_word_ list */
	printf("----------------------------- Load words from the file to list1 -----------------------------\n\n");
	printf("Enter the input file's name: ");
	scanf("%s", &file_name);

	load_word_list(file_name, &list1);
	
	/* Function2 - add_words */
	printf("\n------------------------------------- Add words to list2 ------------------------------------\n\n");
	printf("Enter the language of the second list: ");
	scanf("%s", &sencond_language);
	strcpy(list2.language, sencond_language);
	
	printf("Add words to second list to compare: \n");
	list2_array[0] = 0;

	for (i = 0; i < 13; i++)
	{
		if (i == 12)
		{
			if (list2_array[i] == 0)
			{
				list2.number_of_words += 1;
				printf("The second list is full now!\n\n");
				strcpy(list2_word_buffer, " ");
				break;
			}
			else 
			{
				i--;
				list2.number_of_words = i;
				scanf("%s", &list2_word_buffer);
				check = add_word(&list2, list2_word_buffer);
			}
		}
		else
		{
			list2.number_of_words = i;
			if (list2_array[i] == 0)
			{
				scanf("%s", &list2_word_buffer);
				check = add_word(&list2, list2_word_buffer);
			}
			else
			{
				i--;
				list2.number_of_words = i;
				scanf("%s", &list2_word_buffer);
				check = add_word(&list2, list2_word_buffer);
			}
			list2_array[i + 1] = check;
		}
	}

	/* Function3 - contain */
	printf("--------------------------- Check if the word is in the first list --------------------------\n\n");
	printf("Enter a word you want to find in the first list: ");
	scanf("%s", &contain_input);

	check = contains(&list1, contain_input);
	if (check == 1) 
	{
		printf("The word is found in the first list.\n\n");
	}
	else 
	{
		printf("The word can't be able to find in the first list.\n\n");
	}

	/* Function4 - equal_lists */
	printf("----------------------------------- Two lists' comparison -----------------------------------\n\n");
	
	check = equal_lists(&list1, &list2);

	if (check == 1) 
	{
		printf("The two list is equal.\n\n");
	}
	else 
	{
		printf("The two list is unequal.\n\n");
	}

	/* Function5 - display*/
	printf("----------------------------------- Display two lists ------------------------------------\n\n");
	display_word_list(&list1, &list2);

	printf("\n");
	system("pause");
	return 0;
}

void load_word_list(char* file_name, word_list* list1) 
{
	FILE* inp;
	inp = fopen(file_name, "r");
	list1->number_of_words = 0;

	int i = 0;
	fscanf(inp, "%s", &(*list1).language);
	
	while (fscanf(inp, "%s", &(*list1).words[i]) != EOF)
	{
		list1->number_of_words++;
		i++;
	}
}

int add_word(word_list* list2, char* list2_word_buffer)
{
	int check = 0;
	int i, j, k;

	i = list2->number_of_words - 1;
	k = list2->number_of_words - 1;
	j = k;

	if (i <= 11)
	{
		i++;
		k++;
		j = k;
		if (j == 0)
		{
			strcpy(list2->words[i], list2_word_buffer);
			return check;
		}
		for (j; j > 0; j--)
		{
			if (strcmp(list2_word_buffer, list2->words[j - 1]) == 0)
			{
				printf("The new input is as same as the elder one.\n");
				strcpy(list2_word_buffer, " ");
				strcpy(list2->words[i], " ");
				check = 1;
				return check;
				break;
			}
			else
			{
				strcpy(list2->words[i], list2_word_buffer);
			}
		}
	}
}

int contains(word_list* list1, char* contain_input)
{
	int i, check = 1;
	
	for (i = 0; i < 12; i++)
	{
		if ((strcmp(list1->words[i], contain_input)) == 0) 
		{
			check = 1;
			return check;
		}
		else 
		{
			check = 0;
		}
	}
	return check;
}

int equal_lists(word_list* list1, word_list* list2)
{
	int i, j, check = 0, k = 0;

	if ((strcmp(list1->language, list2->language)) == 0)
	{
		if (list1->number_of_words == list2->number_of_words)
		{
			for(i = list2->number_of_words - 1; i > -1; i--)
			{
				check = contains(list1, list2->words[i]);
				if (check == 0)
				{
					return check;
				}
				else 
				{
					continue;
				}
			}
		}
		else 
		{
			return check;
		}
	}
	else 
	{
		return check;
	}
	
	return check;
}

void display_word_list(word_list* list1, word_list* list2) 
{
	int i, j, k, l, m;
	float a, b;

	a = ((list1->number_of_words) / 4);
	b = ((list2->number_of_words) / 4);
	i = int(a);
	j = int(b);

	printf("List1:\n\n");
	printf("%14cColumn1%14cColumn2%14cColumn3%14cColumn4\n", ' ', ' ', ' ', ' ');
	
	m = 0;

	for (k = 0; k < i; k++) 
	{
		printf("%21s%21s%21s%21s\n", list1->words[m], list1->words[m + 1], list1->words[m + 2], list1->words[m + 3]);
		m = m + 4;
	}
	
	l = k + 2;
	
	if ((a - i) != 0)
	{
		k = (a - i) * 4;
		for (k; k = 0; k--)
		{
			printf("%s%13c", list1->words[l]);
			l += 1;
		}
	}

	printf("\nList2:\n\n");
	printf("%14cColumn1%14cColumn2%14cColumn3%14cColumn4\n", ' ', ' ', ' ', ' ');

	m = 0;

	for (k = 0; k < i; k++)
	{
		printf("%21s%21s%21s%21s\n", list2->words[m], list2->words[m + 1], list2->words[m + 2], list2->words[m + 3]);
		m = m + 4;
	}

	l = k + 2;

	if ((b - i) != 0)
	{
		k = (b - i) * 4;
		for (k; k = 0; k--)
		{
			printf("%s%13c", list2->words[l]);
			l += 1;
		}
	}
}