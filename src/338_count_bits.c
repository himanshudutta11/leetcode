#include<stdio.h>
#include<stdlib.h>
int* countBits(int n, int* returnSize) {
    int *arr_count = (int *)malloc(sizeof(int)*(n+1));
    for(int i = 0; i <= n; i++)
    {
        int index = i;
        int sum = 0;
        while(index)
        {
            if(index & 1)
            {
                sum++;
            }
            index = index >> 1;
        }
        arr_count[i] = sum;
    }
    returnSize = n+1;
    return arr_count;
}
int main()
{
    int num;
    int *arr = countBits(5, &num);
    for(int i = 0; i < num; i++)
    {
        printf("%d,", arr[i]);
    }
}