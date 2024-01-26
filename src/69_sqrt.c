#include<stdio.h>
int mySqrt(int x) {
    int left = 1;
    int right = (x+1)/2;
    while(left <= right)
    {
        int mid = left+(right-left)/2;
        long k = mid*mid;
        if(k == x)
        {
            return mid;
        }
        if(k < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return right;
}
int main()
{
    printf("%d\n", mySqrt(10));
    return 0;
}