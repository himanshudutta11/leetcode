
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int *memo = (int *)malloc((strlen(s)+1) * sizeof(int));
    memo[strlen(s)] = 1;
    for(int i = strlen(s)-1; i >= 0 ; i--)
    {
        int ans = 0; 
        for(int j = 0; j < wordDictSize; j++)
        {
            if(strncmp(s+i, wordDict[j], strlen(wordDict[j])) == 0)
            {
                ans = ans || memo[i+strlen(wordDict[j])] == 1;
            }
        }
        memo[i] = ans ? 1 : 0;
        printf("memo[%d] = %d\n", i, memo[i]);
    }
    return memo[0] == 1;
}
int main()
{
    char *arr[] = {"leet","code"};
    char **wordDict = (char **)malloc(sizeof(char *)*2);
    for(int i = 0; i < 2; i++)
    {
        wordDict[i] = (char *)malloc(sizeof(char)*strlen(arr[i]));
        strcpy(wordDict[i], arr[i]);
    }
    printf("%d", wordBreak("leetcode", wordDict, 2));
    return 0;
}