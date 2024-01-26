#include<stdio.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    char prefix[] = "";
    int i = 0;
    int j = 0;
    for(i = 0; strs[0][i] != '\0'; i++)
    {
        char str_char = strs[0][i];
        for(j = 1; j < strsSize; j++)
        {
            if(strs[j][i] != str_char)
            {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    strs[0][i] = '\0';
    return strs[0];
}
int main()
{
    char *strs[] = {"flight", "flower", "flop"};
    printf("%s", longestCommonPrefix(strs, sizeof(strs)/sizeof(strs[0])));

    return 0;
}