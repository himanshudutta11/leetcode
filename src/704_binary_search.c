#include<stdio.h>

int search(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize-1;
    while(low < high)
    {
        int mid = (low + high)/2;
        if(target > nums[mid])
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }
    return (target == nums[low])? low : -1;

}
/*
int recursive_search(int* nums, int low, int high, int target)
{
    if(low < high)
    {
        int mid = (low + high)/2;

        if(target < nums[mid])
        {
            return recursive_search(nums, low, mid, target);
        }
        else
        {
            return recursive_search(nums, mid+1, high, target);
        }
    }
    return (target == nums[low])? low : -1;

}
int search(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize -1;

    return recursive_search(nums, low, high, target);
}*/
int main()
{
    int arr[] = {-1,0,3,5,9,12};
    printf("%d", search(arr, 6,12));
    return 0;
}