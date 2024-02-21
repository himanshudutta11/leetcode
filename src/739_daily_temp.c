#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int stack[10000] = {0};
int top = -1;
void push(int num)
{
    if(top < 10000-1)
    {
        top++;
        stack[top] = num;
    }
}
int pop()
{
    int num = -1;
    if(top != -1)
    {
        num = stack[top--];
    }
    return num;
}
bool isEmpty()
{
    if(top == -1) return true;
    return false;
}
int top_element()
{
    if(!isEmpty())
    {
        return stack[top];
    }
    return -1;
}
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;
    int *answer = (int *)calloc(temperaturesSize , sizeof(int));
    for(int i = temperaturesSize - 1; i >= 0; i--)
    {
        while(!isEmpty() && temperatures[i] >= temperatures[top_element()])
        {
            pop();
        }
        if(!isEmpty())
        {
            answer[i] = top_element() - i;
        }
        push(i);
    }
    return answer;
}
int main()
{
    int temp[] = {73,74,75,71,69,72,76,73};
    int ans_size = 0;
    int *answer = dailyTemperatures(temp, sizeof(temp)/ sizeof(temp[0]),&ans_size);

    for(int i = 0; i < ans_size; i++)
    {
        printf("%d , ", answer[i]);
    }

    return 0;
}