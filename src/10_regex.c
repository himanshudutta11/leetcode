#include<stdio.h>
#define NOT_MATCH(A, B) (((B) == '.' && (A) == 0) || ((B) != '.' && (A) != (B)))
#define MATCH(A, B)     ((A) == (B) || (B) == '.')
#include<stdio.h>
#include<stdbool.h>
bool rec_match(char *s, char *p, int *try) {
    if (*p == 0)
	{
		return *s == 0;
	}
    if (*(p + 1) == '*') 
	{
        while (*try) 
        {
			if (rec_match(s, p + 2, try)) 
			{
				return true;
			}
			if (NOT_MATCH(*s, *p)) 
			{
				return false;
			}
			s++;
		}
		*try = 0;
		return false;
	}
	if (NOT_MATCH(*s, *p)) 
	{
		return false;
	}
	return rec_match(s + 1, p + 1, try);
}
bool isMatch(char* s, char* p) {
    int try = 1;
	return rec_match(s, p, &try);
}
int main()
{
	printf("%d\n", isMatch("aaaa", "a*"));
	return 0;
}