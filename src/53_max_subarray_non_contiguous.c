#include<stdio.h>
int maxSubArray(int* nums, int numsSize) {
    int num_comb = 1 << numsSize;
    int max_sum = 0;
    for(int i = 1; i < num_comb; i++)
    {
        int index = i;
        int sum = 0;
        int j = 0;
        while(index)
        {
            if(index & 1)
            {
                sum += nums[j];
            }
            index = index >> 1;
            j++;
        }
        if(max_sum < sum)
        {
            max_sum = sum;
        }
    }
    return max_sum;
}
int main()
{
    int array[] = {-1,2,4,5,6};
    printf("%d", maxSubArray(array, sizeof(array)/sizeof(array[0])));
}