#include<stdio.h>
#include<stdbool.h>
/*
int missingInteger(int* nums, int numsSize) {
    int sum = 0;
    for(int i = 0; i < numsSize; i++)
    {
        int j = i;
        int seq_sum = 0;
        while(j >= 0)
        {
            if((nums[j] != nums[j-1]+1) && (j >0))
            {
                break;
            }
            seq_sum += nums[j];
            j--;
        }
        //bool found = false;
        for(int k = 0; k < numsSize; k++)
        {
            if(seq_sum == nums[k])
            {
                seq_sum++;
                k = 0;
            }
        }
        if((seq_sum > sum))
        {
            sum = seq_sum;
        }
        printf("seq_sum: %d sum: %d \n", seq_sum, sum);
    }
    return sum;
}*/
int missingInteger(int* nums, int numsSize) {
    int sum = nums[0];
    for(int j = 1; j < numsSize && nums[j] == nums[j-1] + 1; j++)
    {
        sum += nums[j];
    }
    bool sum_set[51] = {false};
    for(int i = 0; i < numsSize; i++)
    {
        sum_set[nums[i]] = true;
    }
    for(int x = sum; ; x++)
    {
        if(x >= 51 || !sum_set[x])
        {
            return x;
        }
    }
}
int main()
{
    int arr[] = {1,3,2,5,4,5, 6};
    //int arr[] = {3,4,5,1,12,14,13};
    printf("%d\n", missingInteger(arr, sizeof(arr)/sizeof(arr[0])));
    return 0;
}