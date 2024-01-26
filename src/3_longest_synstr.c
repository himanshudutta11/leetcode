#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int lengthOfLongestSubstring(char* s) {
    int *hashtable = (int *)calloc(255, sizeof(int));
    int sum = 0;
    int count = 0;
	int key = 0;
	int index = 0;
	int left = 0;
	int right = 0;
	int n = 0;
    while(*s != '\0')
    {
        key = (int)*s++;
		index++;
		n++;
		left = index - hashtable[key];
		hashtable[key] = index;
		n = (n < left)? n : left;
		right = (right > n)? right : n;
		printf("left = %d, n = %d, right = %d, index = %d\n", left, n, right, index);
    }
    free(hashtable);

    return right;
}
int main()
{
	char *str = "dvdf";
	
	printf("%d", lengthOfLongestSubstring(str));
	return 0;
}