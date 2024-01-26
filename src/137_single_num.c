#include<stdio.h>
int singleNumber(int *nums, int numsSize){
    int a = 0;
    int b = 0;

    for (int i = 0; i < numsSize; i++) {
        b = ~a & (b ^ nums[i]);
        a = ~b & (a ^ nums[i]);
        printf("b = 0x%x a = 0x%x\n", b, a);
    }

    return b;
}
int main()
{
    int array[] = {9,3,9,9,7,7,7};

    printf("the num is: %d", singleNumber(array,sizeof(array)/sizeof(array[0])));

    return 0;
}