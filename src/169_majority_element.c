#include<stdio.h>
int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int major_elem = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(count == 0)
        {
            major_elem = nums[i];
        }
        if(major_elem == nums[i])
        {
            count++;
        }
        else
        {
            count--; 
        }
    }
    return major_elem;
}
int main()
{
    int arr[] = {2,2,1,1,1,2,2,3,3};
    printf("%d", majorityElement(arr, sizeof(arr)/sizeof(arr[0])));
    return 0;
}