#include<stdio.h>
#include<string.h>
char* longestPalindrome(char* s) {
    int i, j, k;
    int max_length = 0;
    int pal_length = 0; 
    int length = strlen(s);
    int index = 0;
    for(i = 0, j = 0, k = 0; max_length < (length - k)*2; j = k, i = k)
    {
        while(j+1 < length && s[j] == s[j+1])
        {
            j++;
        }
        k = j+1;
        while(i > 0 && j+1 < length && s[i-1] == s[j+1])
        {
            i--;
            j++;
        }
        pal_length = j - i + 1;
        if(max_length < pal_length)
        {
            max_length = pal_length;
            index = i;
        }
    }
    s = s + index;
    s[max_length] = '\0';

    return s;
}
int main()
{
    char *s = "babaa";

    char *t = longestPalindrome(s);

    printf("%s\n", t);

    return 0;
}