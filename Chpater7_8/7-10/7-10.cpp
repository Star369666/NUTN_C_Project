#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void vote_and_percent(char[4], int[5][5], int[4], float[4]);
int get_max_index(float[4], int, int);
void over_half_or_not(float[4], char[4], int[4]);
void printf_result(char[4], int[4], float[4], int[5][5]);

int main(void)
{
    char candidate[4] = { 'A', 'B', 'C', 'D' }, candidate_2[4] = { 'A', 'B', 'C', 'D' };
    int vote_sum[4] = { 0, 0, 0, 0 }, vote_sum_2[4] = {0, 0, 0, 0};
    float vote_ave[4], vote_ave_2[4];
    int vote[5][5] = {{1, 192, 48, 206, 37},
                      {2, 147, 90, 312, 21},
                      {3, 186, 12, 121, 38},
                      {4, 114, 21, 408, 39},
                      {5, 267, 13, 382, 29}};
   
    int vote_2[5][5] = {{1, 192, 48, 206, 37},
                        {2, 147, 90, 312, 21},
                        {3, 186, 12, 121, 38},
                        {4, 114, 21, 108, 39},
                        {5, 267, 13, 382, 29}};

    int i;

    vote_and_percent(candidate, vote, vote_sum, vote_ave);
    vote_and_percent(candidate_2, vote_2, vote_sum_2, vote_ave_2);
    printf_result(candidate, vote_sum, vote_ave, vote);
    over_half_or_not(vote_ave, candidate, vote_sum);
    printf_result(candidate_2, vote_sum_2, vote_ave_2, vote_2);
    over_half_or_not(vote_ave_2, candidate_2, vote_sum_2);

    system("pause");
    return 0;
}

void vote_and_percent(char candidate[4], int vote[5][5], int vote_sum[4], float vote_ave[4])
{
    int row, column;
    int vote_all = 0;
    int i;

    for (row = 0; row < 5; row++)
    {
        for (column = 1; column < 5; column++)
        {
            vote_sum[column - 1] = vote_sum[column - 1] + vote[row][column];
        }
    }

    //printf("The vote is \na = %d\nb = %d\nc = %d\nd = %d\n\n", vote_sum[0], vote_sum[1], vote_sum[2], vote_sum[3]);

    for (i = 0; i < 4; i++)
    {
        vote_ave[i] = vote_sum[i];
    }

    for (i = 0; i < 4; i++)
    {
        vote_all = (vote_all + vote_sum[i]);
    }

    for (i = 0; i < 4; i++)
    {
        vote_ave[i] = (vote_ave[i] / vote_all) * 100;
    }

    //printf("The average is \na = %.2f %%\nb = %.2f %%\nc = %.2f %%\nd = %.2f %%\n\n", vote_ave[0], vote_ave[1], vote_ave[2], vote_ave[3]);
}

int get_max_index(float vote_ave[4], int index_new, int max)
{
    int i;
    float large_number;
    int n;

    large_number = vote_ave[index_new];
    n = index_new;

    for (i = index_new; i < max; i++)
    {
        if (vote_ave[i] > large_number)
        {
            large_number = vote_ave[i];
            n = i;
        }
    }
    
    //printf("n=%d\n", n);
    
    return (n);
}

void over_half_or_not(float vote_ave[4], char candidate[4], int vote_sum[4])
{
    int max = 3, i;
    int new_title, index_max;
    float change_float;
    char change_char;
    int change_int;

    /* The averages are: 33.8   6.9   53.3    6.1 */

    for (new_title = 0; new_title < 3; new_title++)
    {
        index_max = get_max_index(vote_ave, new_title, max);

        if (new_title != index_max)
        {
            change_float = vote_ave[index_max];
            vote_ave[index_max] = vote_ave[new_title];
            vote_ave[new_title] = change_float;
            
            change_char = candidate[index_max];
            candidate[index_max] = candidate[new_title];
            candidate[new_title] = change_char;

            change_int = vote_sum[index_max];
            vote_sum[index_max] = vote_sum[new_title];
            vote_sum[new_title] = change_int;
        }
        //printf("Now is %.2f %.2f %.2f %.2f\n", vote_ave[0], vote_ave[1], vote_ave[2], vote_ave[3]);
        //printf("\nNow char is %c %c %c %c\n\n", candidate[0], candidate[1], candidate[2], candidate[3]);
    }

    if (vote_ave[0] > 50.0) 
    {
        printf("\nThe candidate %c with %d( %.2f%% ) votes is the winner!\n\n", candidate[0], vote_sum[0],vote_ave[0]);
    }
    
    if (vote_ave[0] <= 50) 
    {
        printf("\nA runoff between the two candidates: candidate %c with %d( %.2f%% ) votes and candidate %c with %d( %.2f%% ) votes!\n\n", candidate[0], vote_sum[0], vote_ave[0], candidate[1], vote_sum[1],vote_ave[1]);
    }
}

void printf_result(char candidate[4], int vote_sum[4], float vote_ave[4], int vote[5][5]) 
{
    int i, row, column;
    printf("\n%21sCandidate%8sCandidate%7sCandidate%8sCandidate\n%5sPrecinct%12sA%16sB%15sC%16sD\n", "", "", "", "", "", "", "", "", "");

    for (i = 0; i < 42; i++)
    {
        printf("¢w¢w");
    }

    printf("\n");

    for (row = 0; row < 5; row++) 
    {
        printf("%9s", "", "");
        for (column = 0; column < 5; column++)
        {
            printf("%d%14s", vote[row][column], "");
        }
        printf("\n");
    }

    for (i = 0; i < 42; i++)
    {
        printf("¢w¢w");
    }

    printf("\nVotes:\n");
    for (i = 0; i < 4; i++) 
    {
        printf("Candidate %c -> %d votes (%.2f)%%\n", candidate[i], vote_sum[i], vote_ave[i]);
    }
}