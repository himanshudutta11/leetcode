#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int* lastVisitedIntegers(char** words, int wordsSize, int* returnSize) {
    int num_arr[100];
    int stack_num[100];
    int top = -1;
    int index = -1;
    int size = 0;
    printf("wordsSize = %d\n", wordsSize);
    int cons = 0;
    for(int i = 0; i < wordsSize; i++)
    {
        printf("words[%d] = %s\n", i, words[i] );
        char *word_str = words[i];
        //printf("(word_str == \"prev\") = %d\n", (word_str == "prev"));
        if(strcmp(word_str,"prev") == 0)
        {
            if((index >= 0))
            {
                num_arr[size++] = stack_num[index--];
            }
            else
            {
                num_arr[size++] = -1;
            }
            printf("size = %d num_arr[%d] = %d top = %d index = %d \n", size, size-1, num_arr[size-1], top, index);
        }
        else
        {
//            if(word_str[0] < '9' && word_str[0] > '0')
            {
                int sum = 0;
                for(int j = 0; word_str[j] != '\0'; j++)
                {
                    sum = sum * 10 + word_str[j] - '0';
                }
                top++;
                stack_num[top] = sum;
                index = top;
            }
            printf("top = %d stack_num[%d] = %d\n", top, top, stack_num[top]);
        }
    }
    *returnSize = size;
    printf("size = %d\n", size);
    int *return_arr = (int *)malloc(sizeof(int)*size);
    for(int i = 0; i < size; i++)
    {
        return_arr[i] = num_arr[i];
        //printf("%d,", return_arr[i]);
    }
    return return_arr;
}
int main()
{
    //char *words[] = {"1","2","prev","prev","prev"};
    //char *words[] = {"1","prev","2","prev","prev"};
    char *words[] = {"prev","prev","prev","58","99","prev","10","prev"};
    int num;
    int *arr = lastVisitedIntegers(words, 8, &num);
    for(int i = 0; i < num; i++)
    {
        printf("%d, ", arr[i]);
    }

    return 0;
}