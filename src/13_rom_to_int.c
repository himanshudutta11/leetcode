#include<stdio.h>
#include<string.h>
int romanToInt(char* s) {
    int len = strlen(s);
    int num = 0;
    for(int i = 0; i < len; i++)
    {
        switch(s[i])
        {
            case 'M':
            {
                num += 1000;
                break;
            }
            case 'D':
            {
                num += 500;
                break;
            }
            case 'C':
            {
                if(s[i+1] == 'D' || s[i+1] == 'M')
                {
                    num -= 100;
                }
                else
                {
                    num += 100;
                }
                break;
            }
            case 'L':
            {
                num += 50;
                break;
            }
            case 'X':
            {
                if(s[i+1] == 'L' || s[i+1] == 'C')
                {
                    num -= 10;
                }
                else
                {
                    num += 10;
                }
                break;
            }
            case 'V':
            {
                num += 5;
                break;
            }
            case 'I':
            {
                if(s[i+1] == 'V' || s[i+1] == 'X')
                {
                    num -= 1;
                }
                else
                {
                    num += 1;
                }
                break;
            }
        }
    }

    return num;
}
int main()
{
    printf("%d\n", romanToInt("III"));
}