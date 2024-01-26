#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int *char_count(char * s)
{
    int *char_hash = (int *)calloc(26,sizeof(int));
    for(int i = 0; s[i] != '\0'; i++)
    {
        char_hash[s[i] - 'a']++;
    }
    return char_hash;
}
int diff(const int *a, const int *b)
{
    return *a - *b;
}
bool closeStrings(char* word1, char* word2) {
    if(strlen(word1) != strlen(word2))
    {
        return false;
    }
    int *word1_char_hash = char_count(word1);
    int *word2_char_hash = char_count(word2);

    for(int i = 0; i < 26; i++)
    {
        if(((word1_char_hash[i] != 0 && word2_char_hash[i] == 0))|| 
            ((word2_char_hash[i] != 0 && word1_char_hash[i] == 0)))
        {
            return false;
        }
    }

    qsort(word1_char_hash, 26, sizeof(int), (int (*)(const void *, const void *))diff);
    qsort(word2_char_hash, 26, sizeof(int), (int (*)(const void *, const void *))diff);

    for(int i = 0; i < 26; i++)
    {
        if(word1_char_hash[i] != word2_char_hash[i])
        {
            return false;
        }
    }

    free(word1_char_hash);
    free(word2_char_hash);

    return true;
}
int main()
{
    char *word1 = "cabbba";
    char *word2 = "abbccc";

    printf("%d", closeStrings(word1, word2));

    return 0;
}