#include<stdio.h>

double myPow(double x, int n) {
    double mypow = 1;
    unsigned abs_n;
    
    if(n == -2147483648) n = -(n+1);
    
    abs_n = (n > 0)? n: (-n);
    
    if((x == 1) || (n == 0)) return 1;
    if (n == 1) return x;
    
    x = (n > 0) ? x : 1/x;

    while(abs_n)
    {
        mypow *= x;
        abs_n = abs_n >> 1;
    }
    return mypow;
}

int main()
{
    printf("%f", myPow(2.00000, -2147483648));
    return 0;
}
