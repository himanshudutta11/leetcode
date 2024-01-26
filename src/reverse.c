#include<stdio.h>
int reverse(int x){
    int y= 0;

    while(x){
        int d = x%10;
        // Check the overflow case
		printf("%d %d\n", (signed)(0x80000000-d)/10,(0x80000000-d)/10);
        if((x > 0 && (y > (0x7FFFFFFF-d)/10)) ||
           ((x < 0) &&(y < (int)(0x80000000-d)/10)))
        {
            return 0;
        } 
        y = y*10 + d;        
        x = x /10;
    }
    return y;
}
int main()
{
	printf("reverse: %d", reverse(-123));
	return 0;
}