#include<stdio.h>
int minimumPushes(char* word) {
    int count = 0;
    int inc = 1;
    int hashmap[26] = {0};
    for(int i = 0; word[i] != '\0'; i++)
    {
        hashmap[word[i] - 'a']++;
    }
    for(int i = 0; i < 24; i++)
    {
        for(int j = i+1; j < 25; j++)
        {
            if(hashmap[i] < hashmap[j])
            {
                int temp = hashmap[i];
                hashmap[i] = hashmap[j];
                hashmap[j] = temp;
            }
        }
    }
    for(int i = 0; i < 26; i++)
    {
        printf("i %d, hashmap = %d\n", i, hashmap[i]);
    }
    int j = 0;
    for(int i = 0; i < 25; i++)
    {
        if(hashmap[i] == 0)
        {
            break;
        }
        if(i % 8 == 0)
        {
            j++;
        }
        count += hashmap[i]*j;
        printf("i = %d hashmap = %d j = %d count %d\n", i, hashmap[i], j, count);
    }
    return count;
}
int main()
{
    char *s = "abcde";
    printf("%d", minimumPushes(s));
    return 0;
}