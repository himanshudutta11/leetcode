#include<stdio.h>
#include<string.h>
int strStr(char* haystack, char* needle) {
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);
    int i;
    for(i = 0; i < (haystack_len - needle_len)+1; i++)
    {
        int j = 0;
        int k = i; 
        while(haystack[k] == needle[j])
        {
            k++;
            j++;
            if(needle[j] =='\0')
            {
                return i;
            }
        }
    }
    return -1;
}
int main()
{
    printf("%d", strStr("a", "a"));

    return 0;
}