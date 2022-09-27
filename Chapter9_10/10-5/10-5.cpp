#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int x;
	int y;
	int z;
	int m;
	char name[10];
}address_t;

typedef struct
{
	char address1[10];
	char address2[10];
}address_list;

int scan_address(FILE*, address_t*);
void print_address(FILE*, address_t*, int);
int local_address(address_t*, address_t*, address_list*, int, int[4950]);

int main(void)
{
	FILE* inp;
	inp = fopen("input.txt", "r");
	
	address_t address[100];
	address_list list[4950];
	int count, how_many_times, i;
	int result_array[4950];
	//int I = 0;

	count = scan_address(inp, address);
	print_address(inp, address, count);
	how_many_times = local_address(address, address, list, count, result_array);
	
	for (i = 0; i < how_many_times; i++)
	{
		//I++;
		//printf("I=%d, i now is %d, result now is\n", I, i, result_array[i]);
		if (result_array[i] == 1) 
		{
			printf("Machines %s and %s are on the same local network.\n", list[i].address1, list[i].address2);
		}
	}
	
	printf("\n");
	system("pause");
	return 0;
}

int scan_address(FILE*, address_t* address)
{
	FILE* inp;
	inp = fopen("input.txt", "r");

	int i = 0, count;

	//printf("Enter how many address to input(maximum is 100): ");
	//scanf("%d", &count);
	//printf("%d\n", count);

	while(fscanf(inp, "%d.%d.%d.%d %s", &address[i].x, &address[i].y, &address[i].z, &address[i].m, &address[i].name) != EOF)
	{
		if (address[i].x != 0 && address[i].y != 0 && address[i].z == 0 && address[i].m == 0 && address[i].name == "none")
		{
			i++;
			break;
		}
		else 
		{
			i++;
			if (i == 99)
			{
				address[100].x = 0;
				address[100].y = 0;
				address[100].z = 0;
				address[100].m = 0;
				strcpy(address[100].name, "none");
				break;
			}
			else
			{
				//printf("%d.%d.%d.%d  %s\n", address[i].x, address[i].y, address[i].z, address[i].m, address[i].name);
			}
		}
	}
	
	count = i;

	printf("The first to %dth address: \n", count);

	printf("\n");

	return(count);
}

void print_address(FILE*, address_t* address, int count) 
{
	int i, for_count = 1;

	for (i = 0; i < count; i++)
	{
		if (i < 9) 
		{
			printf("IP[0%d]: %d.%d.%d.%d  %s\n", for_count, address[i].x, address[i].y, address[i].z, address[i].m, address[i].name);
			for_count++;
		}
		else if(i >= 9)
		{
			printf("IP[%d]: %d.%d.%d.%d  %s\n", for_count, address[i].x, address[i].y, address[i].z, address[i].m, address[i].name);
			for_count++;
		}
	}
	printf("\n");
}

int local_address(address_t* first, address_t* second, address_list* list, int count, int array[4950])
{
	int i, j, k = 0, result = 0, how_many_times;

	how_many_times = ((count - 1) * count) / 2;

	for (i = 0; i < count; i++) 
	{
		for (j = i + 1; j < count; j++) 
		{
			if (first[i].x == second[j].x && first[i].y == second[j].y)
			{
				//printf("Machines %s and %s are on the same local network.\n", first[i].name, second[j].name);
				if (first[i].x != 0 && first[i].y != 0 && second[j].x != 0 && second[j].y != 0) 
				{
					result = 1;
					strcpy(list[k].address1, first[i].name);
					strcpy(list[k].address2, second[j].name);
					array[k] = result;
					k++;
				}
				else 
				{
					result = 0;
					strcpy(list[k].address1, first[i].name);
					strcpy(list[k].address2, second[j].name);
					array[k] = result;
					k++;
				}
			}
			else
			{
				result = 0;
				strcpy(list[k].address1, first[i].name);
				strcpy(list[k].address2, second[j].name);
				array[k] = result;
				k++;
			}
		}
	}

	return(how_many_times);
}