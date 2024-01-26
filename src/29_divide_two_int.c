#include<stdio.h>
#define INT_MIN -2147483648
#define INT_MAX 2147483647
/*int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }
    else if(dividend == INT_MIN && divisor == 1)
    {
        return INT_MIN;
    }
    else if(divisor == INT_MIN)
    {
        if(dividend == INT_MIN)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int sign = 1;
        int value = 0;
        
        if(divisor < 0)
        {
            divisor = - divisor;
            sign = -1;
        }
        if(dividend > 0)
        {
            while (dividend >= divisor)
            {
                dividend -= divisor;
                value++;
            }
        }
        else
        {
            while(dividend <= -divisor)
            {
                dividend += divisor;
                value++;
            }
            value = -value;
        }
        return sign*value;
    }
}*/

int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }
    else if(dividend == INT_MIN && divisor == 1)
    {
        return INT_MIN;
    }
    else if(dividend == 0)
    {
        return 0;
    }

    int sign = 1;
    if(dividend > 0)
    {
        dividend = -dividend;
        sign = -sign;
    }
    if(divisor > 0)
    {
        divisor = -divisor;
        sign = -sign;
    }

    int candidate[32] = {divisor};
    int index = 1;

    while(candidate[index -1] >= dividend - candidate[index -1])
    {
        candidate[index] = candidate[index -1] + candidate[index -1];
        index++;
    }
    
    int value = 0;
    for(int i = index - 1; i >= 0; i--)
    {
        if(candidate[i] >= dividend)
        {
            value += (1 << i);
            dividend -= candidate[i];
        }
    }

    return sign * value;
}
int main()
{
    printf("%d \n", divide(-1,-2));
    printf("%d\n", divide(10, 3));
    printf("%d\n", divide(7, -3));
    printf("%d\n", divide(-2147483648, 1));
    return 0;
}