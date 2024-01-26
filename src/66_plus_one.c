/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    for(int i = digitsSize - 1; i >= 0; i--)
    {
        if(digits[i] + carry > 9)
        {
            digits[i] = 0;
            carry = 1;
        }
        else
        {
            digits[i] +=carry;
            carry = 0;
            break;
        }
    }
    if(carry == 0 )
    {
        *returnSize = digitsSize;
        return digits;
    }
    else
    {
        int *array = (int *)calloc(digitsSize+1, sizeof(int));
        array[0] = carry;
        for(int i = 1; i <= digitsSize; i++)
        {
            array[i] = digits[i-1];
        }
        *returnSize = digitsSize+1;
        return array;
    }
}
int main()
{
    int digits[4] = {1,2,3,4};
    int retSize = 0;
    int *ret = plusOne(digits, 4, &retSize);

    for(int i = 0; i < retSize; i++)
    {
        printf("ret[%d] = %d\n", i, ret[i]);
    }

}