#include<stdio.h>
#include<string.h>
char* longestPalindrome(char* s) {
	int len = strlen(s);
	int i, j, k;
	int pal_len = 0;
	int max_len = 0;
	int index = 0;
	for(i = 0, j = 0, k = 0; max_len < (len-k)*2; i=k, j=k)
	{
		while(j+1 < len && s[j] == s[j+1])
		{
			j++;
		}
		k = j+1;
		while(i > 0 && j + 1 <len && s[i-1] == s[j+1])
		{
			i--;
			j++;
		}
		pal_len = j-i+1;
		if(max_len < pal_len)
		{
			max_len = pal_len;
			index = i;
		}
	}
	
	s = s+index;
	s[max_len] = '\0';
	return s;
}

int main()
{
	char *str = "aba";
	printf("%s", longestPalindrome(str));
}