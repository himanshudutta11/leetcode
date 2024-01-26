#include<stdio.h>
#include<stdbool.h>
bool isIsomorphic(char* s, char* t) {
    char hashmap_1[255] = {0};
    char hashmap_2[255] = {0};
    for(int i = 0; s[i] != '\0'; i++)
    {
        printf("---------\n");
        printf("%c - %c\n", s[i], t[i]);
        printf("%c - %c\n", hashmap_1[s[i]], hashmap_2[t[i]]);
        if(hashmap_1[s[i]] == 0 && hashmap_2[t[i]] == 0)
        {
            hashmap_1[s[i]] = t[i];
            hashmap_2[t[i]] = s[i];
            printf("%c - %c\n", hashmap_1[s[i]], hashmap_2[t[i]]);
        }
        else if((hashmap_1[s[i]] == t[i]) && (hashmap_2[t[i]] == s[i]))
        {
            printf("%c - %c\n", hashmap_1[s[i]], hashmap_2[t[i]]);
        }
        else
        {
            printf("returning false %c == %c - %c == %c\n", hashmap_1[s[i]], t[i], hashmap_2[t[i]], s[i]);
            printf("returning false %d == %d - %d == %d\n", hashmap_1[s[i]], t[i], hashmap_2[t[i]], s[i]);
            return false;
        }
    }
    return true;
}
int main()
{
    char *s = "egg";
    char *t = "add";
    printf("%d", isIsomorphic(s, t));
    return 0;
}