#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int x, int y)
{
    return (x > y) ? x : y;
}
int candy(int* ratings, int ratingsSize) {
    int *candies = (int *)malloc(sizeof(int)*ratingsSize);

    for(int i = 0; i < ratingsSize; i++)
    {
        candies[i] = 1;
    }

    for(int i = 1; i < ratingsSize; i++)
    {
        if(ratings[i] > ratings[i-1])
        {
            candies[i] = candies[i-1] + 1;
        }
    }

    for(int i = ratingsSize - 2; i >= 0; i--)
    {
        if(ratings[i] > ratings[i+1])
        {
            candies[i] = max(candies[i], candies[i+1]+1);
        }
    }

    int total = 0;

    for(int i = 0; i < ratingsSize; i++)
    {
        total += candies[i];
        printf("i = %d candies = %d total = %d \n", i, candies[i], total);
    }
    free(candies);
    return total;
}
int main()
{
    int ratings[] = {1,0,2};

    printf("%d\n", candy(ratings, 3));

    return 0;
}