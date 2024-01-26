#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define VECTOR_LENGTH 12
typedef struct res{
    char **p;
    int sz;
    int n;
}res_t;
typedef struct buf{
    char *b;
    int sz;
    int n;
}buf_t;

int *new_vector()
{
    int *vector = (int *)malloc(sizeof(int)*VECTOR_LENGTH);
    vector[0] = VECTOR_LENGTH;
    vector[1] = 0;
    return vector;
}
void add_2_vector(int *vec, int i)
{
    if(vec[0] == vec[1])
    {
        vec[0] *= 2;
        vec = realloc(vec, sizeof(int)*vec[0]);
    }
    vec[2+vec[0]++] = i;
}
void add_2_res(res_t *res, char *str)
{
    if(res->sz == res->n)
    {
        res->sz *= 2;
        res->p = realloc(res->p, res->sz*sizeof(char *));
    }
    res->p[res->n++] = str;
}
void add_2_buf(buf_t *buf, int n, char *s, int l)
{
    buf->n = n;
    if(buf->sz <= buf->n + l + 2)
    {
        buf->sz *= 2 + l + 2;
        buf->b = realloc(buf->b, sizeof(char)*buf->sz);
    }
    strncpy(&buf->b[buf->n], s, l);
    buf->n += l;
    buf->b[buf->n] = ' ';
    buf->n++;
}
void func(buf_t *buf, res_t *res, char *s, int **dp, int start, int end)
{
    if(start == end)
    {
        buf->b[--buf->n] = '\0';
        add_2_res(res, strdup(buf->b));
        return;
    }
    int n = buf->n;
    int *vec = dp[start];

    for(int i = 0; i < vec[1]; i++)
    {
        int k = vec[2+i];
        add_2_buf(buf, n, &s[start], k-start);
        func(buf, res, s, dp, k, end);
    }

}
char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    int len = strlen(s);
    int **dp = (int **)calloc(len+1, sizeof(int *));

    dp[0] = new_vector();

    res_t res;
    buf_t buf;

    res.sz = 10;
    res.n = 0;
    res.p = (char **)malloc(sizeof(char *)*res.sz);

    buf.sz = 100;
    buf.n = 0;
    buf.b = (char *)malloc(sizeof(char)*buf.sz);


    for(int i = 0 ; i < len; i++)
    {
        if(dp[i])
        {
            for(int j = 0; j < wordDictSize; j++)
            {
                if(strncmp(s+i, wordDict[j], strlen(wordDict[j])) == 0)
                {
                    add_2_vector(dp[i], i+strlen(wordDict[j]));
                    if(!dp[i+strlen(wordDict[j])])
                    {
                        dp[i+strlen(wordDict[j])] = new_vector();
                    }
                }
            }
        }
    }
    if(dp[len])
    {
        func(&buf, &res, s, dp, 0, len);
    }
    // for(int i = 1; i <= len; i++)
    // {
    //     if(dp[i])
    //     {
    //         free(dp[i]);
    //     }
    // }
    // free(dp);
    free(buf.b);

    *returnSize = res.n;

    return res.p;

}
int main()
{
    char *arr[] = {"cat","cats","and","sand","dog"};
    char **wordDict = (char **)malloc(sizeof(char *)*5);
    for(int i = 0; i < 5; i++)
    {
        wordDict[i] = (char *)malloc(sizeof(char)*strlen(arr[i]));
        strcpy(wordDict[i], arr[i]);
    }
    int returnSize = 0;
    char **str_arr = wordBreak("catsanddog", wordDict, 5, &returnSize);
    printf("returnSize = %d", returnSize);
    for(int i = 0; i < returnSize; i++)
    {
        printf("%s\n", str_arr[i]);
    }

    return 0;
}