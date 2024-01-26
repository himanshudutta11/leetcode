/*
43. Multiply Strings
Medium
6.7K
3.1K
Companies
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/
#include<stdio.h>
long my_pow(int x, int n)
{
	int ret = 1;
	for(int i = 0; i < n; i++)
	{
		ret *= (long)x;
	}
	return ret;
}
char* multiply(char* num1, char* num2) {
    int num1_int[23] = {0};
    int num2_int[23] = {0};
	char *num1_i = num1;
	char *num2_i = num2;
	static char arr[400];
	char rev_arr[400];
	int j = 0;
	int i = 0;
	int total = 0;
	while(*num1_i != '\0')
	{
		total++;
		num1_i++;
	}
	int first_cnt = (total%9 == 0)?9:(total % 9);
	num1_i = num1;
    while(*num1_i != '\0')
    {
        char s = *num1_i++;
        int dig = s - '0';
        num1_int[j] = num1_int[j]*10+dig;
		if(((j != 0)&&(++i == 9)) ||((j == 0)&&(++i == first_cnt)))
		{
			j++;
			i = 0;
		}
    }
	int num1_count = j;
	i = 0; 
	j = 0;
	total = 0;
	while(*num2_i != '\0')
	{
		total++;
		num2_i++;
	}
	first_cnt = (total%9 == 0)?9:(total % 9);
	num2_i = num2;
    while(*num2_i != '\0')
    {
        char s = *num2_i++;
        int dig = s - '0';
        num2_int[j] = num2_int[j]*10+dig;
		if(((j != 0)&&(++i == 9)) ||((j == 0)&&(++i == first_cnt)))
		{
			j++;
			i = 0;
		}
    }
	int num2_count = j;
    printf("num1_count: %d num2_count: %d \n", num1_count, num2_count);
	for(i = 0; i < num1_count; i++)
	{
		printf("num1_int[%d]: %d\t", i, num1_int[i]);
	}
	printf("\n");
	for(i = 0; i < num2_count; i++)
	{
		printf("num2_int[%d]: %d", i, num2_int[i]);
	}
	printf("\n");
	if((num1_count == 1 && num1_int[0] == 0) || (num2_count == 1 && num2_int[0] == 0))
	{
		return "0";
	}
	long mult[num2_count][num1_count];
	printf("int: %d, long: %d, long int : %d \n",sizeof(int), sizeof(long), sizeof(long int));

	for(i = 0; i < num2_count; i++)
	{
		for(j = 0; j < num1_count; j++)
		{
			mult[i][j] = 0;
		}
	}
	for(i = num2_count-1; i >= 0; i--)
	{
		for(j = num1_count-1; j >= 0; j--)
		{
			mult[i][j] = (long)num1_int[j] * (long)num2_int[i];
			printf("mult[%d][%d]: %ld \t", i, j, mult[i][j]);
		}
		printf("\n");
	}
	int res_count = (num1_count > num2_count)?num1_count:num2_count;
	long result[res_count];
	int carry = 0;
	for(i = num1_count-1; i >= 0; i--)
	{
		result[i] = 0;
		for(j = num2_count-1; j >= 0; j--)
		{
			result[i] += mult[j][i];
			if(carry != 0)
			{
				result[i] += carry;
				carry = 0;
			}
		}
//		printf("result[%d]: %ld th1:%ld th2:%ld\n", i, result[i], my_pow(10,10)-1, my_pow(10,10));
		if((result[i] > (my_pow(10,9)-1)) && (i != 0))
		{
			carry = result[i] / my_pow(10,9);
			result[i] = result[i] % my_pow(10,9);
		}
		printf("result[%d]: %ld \n", i, result[i]);
	}
	
    printf("result[0]: %ld \n", result[0]);
/*    if(num1_int == 0){
        return "0";
    }*/
	int num_char = 0;
	for(i = num1_count-1; i >= 0; i--)
	{
		long temp = result[i];
		
		while(temp != 0)
		{
			rev_arr[num_char++] = (temp % 10)+'0';
			temp = temp / 10;
		}
/* 		if(i != 0)
		{
			for(j = 0; j < 9; j++)
			{
				rev_arr[num_char++] = (temp % 10)+'0';
				temp = temp / 10;
			}
		}
		else
		{
			while(temp != 0)
			{
				rev_arr[num_char++] = (temp % 10)+'0';
				temp = temp / 10;
			}
		}
 */	}
    printf("rev_arr: %s \n", rev_arr);
//	rev_arr--;
    i = 0; 
	while(num_char > 0)
	{
		arr[i++] = rev_arr[num_char-1];
		num_char--;
	}
	arr[i] = '\0';
	
    printf("arr: %s\n", arr);
    return arr;
}
int main()
{
	char *num1 = "5423396";
	char *num2 = "5424012638";
	printf("%s", multiply(num1, num2));
	return 0;
}