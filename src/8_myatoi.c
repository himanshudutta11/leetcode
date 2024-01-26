#include<stdio.h>
#include<stdint.h>
#include<limits.h>
int myAtoi(char* s) {
    long long num = 0;
    int sign = 1;

    while(*s == ' ') s++;

    if(*s == '+')
    {
        sign = 1;
        s++;
    }
    else if(*s == '-')
    {
        sign = -1;
        s++;
    }
    
    while(*s >= '0' && *s <= '9')
    {
        num = num*10 + *s++ - '0';
        if(num > INT32_MAX + 1)
        {
            num = (long)INT32_MAX + 1;
        }
    }

    num = num*sign;

    if(num < INT32_MIN) num = INT_MIN;
    if(num > INT32_MAX) num = INT_MAX;

    return (int)num;
}

int main()
{
    char* s = "42";
    printf("%d", myAtoi(s));
    return 0;
}
