#include<stdio.h>
#include<stdbool.h>
bool isPowerOfTwo(int n) {
    if(n <= 0) return false;
    bool ret = false;
    if((n & (n-1)) == 0)
    {
        ret = true;
    }
    return ret;
}
int main()
{
    printf("%d", isPowerOfTwo(16));
    return 0;
}