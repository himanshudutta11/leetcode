#include<stdio.h>
#include<string.h>
void str_reverse(char *start, char *end)
{
    while(start < end)
    {
        char c = *start;
        *start = *end;
        *end = c;
        start++;
        end--;
    }
}
char* reverseWords(char* s) {
    int len = strlen(s);
    char *ptr1 = s;
    char *ptr2 = s+len-1;
    str_reverse(ptr1, ptr2);
    ptr1 = s;
    ptr2 = ptr1 + 1;

    while(*ptr1)
    {
        while(*ptr2 && *ptr2 != ' ')
        {
            ptr2++;
        }

        str_reverse(ptr1,ptr2-1);
        while(*ptr2 == ' ')
        {
            ptr2++;
        }
        ptr1 = ptr2;
    }
    return s;
}
int main()
{
    char s[] = "the sky is blue";
    char *rev = reverseWords(s);
    printf("%s", rev);

    return 0;
}