#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* addBinary(char* a, char* b) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    int num = (len1 > len2)?len1:len2;
    num = num + 2;
    char *result = (char *)malloc(sizeof(char)*num);
    int i = len1 - 1;
    int j = len2 - 1;
    int k = num - 1;
    int carry = 0;
    result[k--] = '\0';
    while(i >= 0 || j >= 0 || carry)
    {
        if(i >= 0)
        {
            carry = carry + a[i] -'0';
            i--;
        }
        if(j >= 0)
        {
            carry = carry + b[j] - '0';
            j--;
        }
        result[k--] = carry % 2 + '0';
        carry = carry / 2;
    }

    return result+k+1;
}

int main()
{
    printf("%s\n", addBinary("11","1"));
    return 0;
}