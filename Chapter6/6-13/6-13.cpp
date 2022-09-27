#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
enum star
{
	start, build_num, number, build_id, identifier, stop
};
star transition(star, char);

int main(void) 
{
	char transition_char;
	star current_state = start;
	
	do 
	{
		if (current_state == identifier) 
		{
			printf(" - Identifier\n"); 
			current_state = start;
		}
		else if (current_state == number) 
		{
			printf(" - Number\n"); 
			if (transition_char == '\n') 
			{
				current_state == stop;
				continue;
			}
			current_state = start;
		}
		scanf("%c", &transition_char); 
		if (transition_char != ' ' && transition_char != '\n')
		{
			printf("%c", transition_char);
		}
		current_state = transition(current_state, transition_char);
	} while (current_state != stop);
	
	system("pause");
	return 0;
}

star transition(star current, char transition_point) 
{
	if (transition_point == ' ')
	{
		if (current == build_id) {
			return identifier;
		}
		else if (current == build_num)
		{
			return number;
		}
		else {
			return start;
		}
	}

	if (transition_point == '\n')
	{
		if (current == build_id)
			printf(" - Identifier\n");
		if (current == build_num)
			printf(" - Number\n");
		return stop;
	}

	if (transition_point == '.')
		return stop;
	
	if ((current == start || current == build_num)&&(isdigit(transition_point)))
	{
		return build_num;
	}
	else 
	{
		return build_id;
	}
}