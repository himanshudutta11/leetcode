#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
bool isPalindrome(char* s) {
    int j = 0;
    int len = strlen(s);
    char *str = (char *)calloc(len, sizeof(char));
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            char t = s[i];
            str[j] = t;
            j++;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            char t = s[i] - 'A' + 'a';
            str[j] = t;
            j++;
        }
        
    }

    str[j--] = '\0';
    printf("%s\n", str);
    int i = 0;
    while(i < j)
    {
        if(str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    char *s = "A man, a plan, a canal: Panama";
    printf("%d", isPalindrome(s));

    return 0;
}