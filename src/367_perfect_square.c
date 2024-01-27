#include<stdio.h>
#include<stdbool.h>
bool isPerfectSquare(int num) {
    int left = 1;
    int right = num;

    while(left <= right)
    {
        int mid = (left + right)/2;
        printf("left = %d right = %d mid = %d\n", left, right, mid);
        if(mid*mid == num)
        {
            return true;
        }
        else if(mid*mid > num)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    return false;
}
int main()
{
    printf("%d\n", isPerfectSquare(16));

    return 0;
}