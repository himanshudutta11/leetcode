#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void generateParenthesisHelper(char ***ans, char *temp, int *total, int index, int left, int right, int n)
{
    if(left > right)
    {
        return;
    }
    if(left == 0 && right == 0)
    {
        (*ans)[(*total)++] = strdup(temp);
        printf("temp: %s, ans: %s total: %d\n", temp, (*ans)[(*total)-1], *total);
        return;
    }
    if(left > 0)
    {
        temp[index] = '(';
        generateParenthesisHelper(ans, temp, total, index+1, left - 1, right,n);
    }
    if(right > 0)
    {
        temp[index] = ')';
        generateParenthesisHelper(ans, temp, total, index+1, left, right - 1,n);
    }
}
char** generateParenthesis(int n, int* returnSize) {
//    printf("Starting generateParenthesis");
    char **ans = (char **)malloc(100*sizeof(char *));
    char *temp = (char*)malloc((2*n+1)*sizeof(char));
    temp[2*n] = '\0';
    int total = 0;
    int index = 0;
    generateParenthesisHelper(&ans, temp, &total, index, n, n, n);
    *returnSize = total;

    return ans;
}
int main()
{
    int n = 6;
    int returnSize = 0;
//    printf("Starting");
    char** ans = generateParenthesis(n, &returnSize);
    printf("returnSize = %d\n", returnSize );
    for(int i = 0; i < returnSize; i++)
    {
        printf("%d th string: %s\n", i, ans[i]);
    }
    return 0;
}