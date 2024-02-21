#include<stdio.h>
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

int evalRPN(char** tokens, int tokensSize) {

    for(int i = 0; i < tokensSize; i++)
    {
        if((tokens[i] == "+") || (tokens[i] == "-") || (tokens[i] == "*") || (tokens[i] == "/"))
        {
            int a = pop();
            int b = pop();
            int c;
            if(tokens[i] == "+")
            {
                c = a + b;
            }
            else if (tokens[i] == "-")
            {
                c = a - b;
            }
            else if (tokens[i] == "*")
            {
                c = a * b;
            }
            else if (tokens[i] == "/")
            {
                c = a / b;
            }
            push(c);
        }
        else
        {
            char *t = tokens[i];
            int sign = 1;
            int j = 0;
            if(t[j] == '-')
            {
                sign = -1;
                j++;
            }
            int sum = 0;
            for(; t[j] != '\0';j++)
            {
                sum = sum * 10 + t[j] - '0';
            }
            sum = sum * sign;
            push(sum);
        }
    }

    return pop();
}
int main()
{
    char *tokens[5] = {"2","1","+","3","*"};
    int tokensSize = 5;

    printf("%d\n", evalRPN(tokens, tokensSize));

    return 0;
}