#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isValid(char* s) {
    int num = strlen(s);
    int stack[num];
    int top = -1;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            top++;
            stack[top] = s[i];
        }
        if((s[i] == ')') || (s[i] == '}') || (s[i] == ']'))
        {
            if(top >= 0)
            {
                char bracket = stack[top--];
                if(((bracket == '(') && (s[i] != ')')) ||
                ((bracket == '{') && (s[i] != '}')) ||
                ((bracket == '[') && (s[i] != ']')))
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (top != -1)
    {
        return false;
    }
    return true;
}
int main()
{
    char *s = "[]";
    printf("%d", isValid(s));
    return 0;
}