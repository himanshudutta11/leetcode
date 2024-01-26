#include<stdio.h>
double myPow(double x, int n) {
    printf("x = %f, n = %d\n", x, n);
    if (n == 0) return 1;
    if(n < 0)
    {
        myPow(1/x, -n);
    }
    return x*myPow(x, n-1);
}
int main()
{

    printf("%f", myPow(2.0,4));
    return 0;
}
