#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len = (len_a > len_b) ? (len_a) : (len_b);
    // char *ans = (char *)calloc((len + 1), sizeof(char));
     char *ans = (char *)malloc((len + 1) * sizeof(char));
    int i;
    int sum = 0;
    for (i = 0; i < len; i++) {
        if (i < len_a && i < len_b) {
            sum += (a[len_a - 1 - i] - '0') + (b[len_b - 1 - i] - '0');
        }
        else if (i < len_a) {
            sum += a[len_a - 1 - i] - '0';
        }
        else if (i < len_b) {
            sum += b[len_b - 1 - i] - '0';
        }
        ans[len - i] = sum % 2 + '0';
        sum /= 2;
    }

    ans[len + 1] = '\0';

    if (sum) {
        ans[0] = sum + '0';
        return ans;
    }
    else {
        return ans + 1;
    }
}
int main(int argc, char **argv)
{
    printf("%s", addBinary(argv[1], argv[2]));

    return 0;
}