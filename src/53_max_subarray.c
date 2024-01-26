#include<stdio.h>
/*int maxSubArray(int* nums, int numsSize) {
    if(numsSize == 1) return nums[0];
    int max_sum = 0;
    for(int i = 0; i < numsSize; i++)
    {
        int sum = 0;
        for(int j = i; j < numsSize; j++)
        {
            sum += nums[j];
            if(max_sum < sum)
            {
                max_sum = sum;
            }
        }
    }
    return max_sum;
}*/
int maxSubArray(int* nums, int numsSize) 
{
    int max_sum = nums[0];
    int sum = 0;
    for(int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        if(sum < nums[i])
        {
            sum = nums[i];
        }
        if(sum > nums[i])
        {
            max_sum = sum;
        }
    }
    return max_sum;
}
int main()
{
    int array[] = {-1,2,-4,5,6};
    printf("%d", maxSubArray(array, sizeof(array)/sizeof(array[0])));
}