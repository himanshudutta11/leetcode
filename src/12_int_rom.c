#include<stdio.h>
#include<stdlib.h>
char* intToRoman(int num) {
    char *s = (char *)calloc(10, sizeof(char));
    int i = 0;
    while(num > 0)
    {
        while(num >= 1000)
        {
            num = num - 1000;
            s[i] = 'M';
            i++;
        }
        if(num >= 900)
        {
            s[i] = 'C';
            s[i+1] = 'M';
            i = i + 2;
            num = num - 900;
        }
        while(num >= 500)
        {
            s[i] = 'D';
            i++;
            num = num - 500;
        }
        if(num >= 400)
        {
            s[i] = 'C';
            s[i+1] = 'D';
            i = i + 2;
            num = num - 400;
        }
        while(num >= 100)
        {
            s[i] = 'C';
            i++;
            num = num - 100;
        }
        if(num >= 90)
        {
            s[i] = 'X';
            s[i+1] = 'C';
            i = i + 2;
            num = num - 90;
        }
        while(num >= 50)
        {
            s[i] = 'L';
            i++;
            num = num - 50;
        }
        if(num >= 40)
        {
            s[i] = 'X';
            s[i+1] = 'L';
            i = i + 2;
            num = num - 40;
        }
        while(num >= 10)
        {
            s[i] = 'X';
            i++;
            num = num - 10;
        }
        if(num >= 9)
        {
            s[i] = 'I';
            s[i+1] = 'X';
            i = i + 2;
            num = num - 9;
        }
        while(num >= 5)
        {
            s[i] = 'V';
            i++;
            num = num - 5;
        }
        if(num >= 4)
        {
            s[i] = 'I';
            s[i+1] = 'V';
            i = i + 2;
            num = num - 4;
        }
        while(num >= 1)
        {
            s[i] = 'I';
            i++;
            num = num - 1;
        }
    }
    
    return s;
}
int main()
{
    int num = 4;
    
    printf("%s\n", intToRoman(num));

    return 0;
}