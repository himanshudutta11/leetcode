#include<stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    int merged[nums1Size+nums2Size];
    int i_1 = 0;
    int i_2 = 0;
    double median = 0;
    for(int i = 0; i < total; i++)
    {
        if((i_1 < nums1Size) && (i_2 < nums2Size))
        {
            if(nums1[i_1] < nums2[i_2])
            {
                merged[i] = nums1[i_1++];
            }
            else
            {
                merged[i] = nums2[i_2++];
            }
			printf("merged[%d] = %d, i_1 = %d i_2 = %d \n", i, merged[i], i_1, i_2);
        }
        else if(i_1 < nums1Size)
        {
            merged[i] = nums1[i_1++];
        }
        else
        {
            merged[i] = nums2[i_2++];
        }
    }

 	if((total%2) == 0)
	{
		median = ((double)merged[total/2-1]+merged[total/2])/2;
	}
	else
	{
		median = (double)merged[total/2];
	}
	printf("median= %f\n", median);
    return median;
}
int main()
{
	int nums1[] = {1,3};
	int nums2[] = {2,7};
	printf("%f\n", findMedianSortedArrays(nums1, 2, nums2, 2));
	//printf("%f\n", findMedianSortedArrays(nums1, 2, nums2, 2));
	
	return 0;
}