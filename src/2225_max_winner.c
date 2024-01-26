#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct hashmap
{
    int key;
    int count;
    struct hashmap *next;
};
struct hashmap *create_hashmap_entry(struct hashmap **hash_table, int key)
{
    //printf("create_hashmap_entry: key: %d *hash_table: %d\n", key, *hash_table);
    struct hashmap *head = *hash_table;
    struct hashmap *node = (struct hashmap *)malloc(sizeof(struct hashmap));
    node->key = key;
    node->count = 0;
    node->next = NULL;
    if(head == NULL)
    {
        *hash_table = node;
    }
    else
    {
        while(head->next != NULL)
        {
            head = head->next;
        }
        head->next = node;
    }
    return node;
}
struct hashmap *find_hashmap_entry(struct hashmap **hash_table, int key)
{
    //printf("find_hashmap_entry: key: %d *hash_table: %d\n", key, *hash_table);
    if(*hash_table == NULL)
    {
        return NULL;
    }
    struct hashmap *head = *hash_table;
    while(head)
    {
        printf("key: %d count: %d\n", head->key, head->count);
        if(head->key == key)
        {
            printf("found: key: %d count: %d\n", key, head->count);
            return head;
        }
        head = head->next;
    }
    printf("Not found: key: %d \n", key);
    return NULL;
}
int** findWinners(int** matches, int matchesSize, int* matchesColSize, int* returnSize, int** returnColumnSizes) {
    int **answer = (int **)calloc(2, sizeof(int *));
    struct hashmap *hash_table = NULL;
    returnColumnSizes = (int **)calloc(2, sizeof(int *));
    returnColumnSizes[0] = (int *)calloc(1, sizeof(int));
    returnColumnSizes[1] = (int *)calloc(1, sizeof(int));
    *returnSize = 2;
    printf("matchesSize: %d\n", matchesSize);
    for(int i = 0; i < matchesSize; i++)
    {
        printf("%d , %d\n", matches[i][0], matches[i][1]);
        if(!find_hashmap_entry(&hash_table, matches[i][0]))
        {
            create_hashmap_entry(&hash_table, matches[i][0]);
        }
        struct hashmap *loser = find_hashmap_entry(&hash_table, matches[i][1]);
        if(!loser)
        {
            loser = create_hashmap_entry(&hash_table, matches[i][1]);
            loser->count++;
        }
        else
        {
            loser->count++;
        }
        // int count = 0;
        // int j = 0;
        // for(j = i+1; j < matchesSize; j++)
        // {
        //     if(matches[i][0] == matches[j][1])
        //     {
        //         break;
        //     }
        // }
        // if(j == matchesSize)
        // {
        //     ans_0[(*returnColumnSizes[0])++] = matches[i][0];
        //     printf("ans_0 : %d returnColumnSizes[0] %d \n", ans_0[*returnColumnSizes[0] - 1], *returnColumnSizes[0] );
        // }
        // if(count == 0)
        // {
        //     ans_1[(*returnColumnSizes[1])++] = matches[i][1];
        //     printf("ans_1 : %d returnColumnSizes[1] %d \n", ans_1[*returnColumnSizes[1] - 1], *returnColumnSizes[1] );
        // }
    }
    struct hashmap *head = hash_table;
    while(head)
    {
        printf("key = %d count : %d\n", head->key, head->count);
        if(head->count == 0)
        {
            (*returnColumnSizes[0])++;
        }
        else if(head->count == 1)
        {
            (*returnColumnSizes[1])++;
        }
        head = head->next;
    }
    printf("*returnColumnSizes[0]: %d *returnColumnSizes[1]: %d\n", *returnColumnSizes[0], *returnColumnSizes[1]);

    answer[0] = (int *)calloc(*returnColumnSizes[0], sizeof(int));
    answer[1] = (int *)calloc(*returnColumnSizes[1], sizeof(int));
    //printf("Allocated answer[0] %d answer[1] %d\n", answer[0] , answer[1]);
    head = hash_table;
    int count0 = 0;
    int count1 = 0;
    while(head)
    {
        if(head->count == 0)
        {
            answer[0][count0++] = head->key;
        }
        else if(head->count == 1)
        {
            answer[1][count1++] = head->key;
        }
        head = head->next;
    }

    return answer;
}
int main()
{
    int matchesColSize;
    int returnSize; 
    int** returnColumnSizes;

    int matches[10][2] = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    int **ip = (int **)calloc(10, sizeof(int *));
    for(int i = 0; i < 10; i++)
    {
        ip[i] = (int *)calloc(2, sizeof(int));
    }
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            ip[i][j] = matches[i][j];
        }
    }
    int **answer = findWinners(ip, 10, &matchesColSize, &returnSize, returnColumnSizes);
    printf("returnColumnSizes[0]: %d, returnColumnSizes[1]: %d\n", returnColumnSizes[0], returnColumnSizes[1]);
    for(int i =0; i < *returnColumnSizes[0]; i++)
    {
        printf("%d, ", answer[0][i]);
    }
    for(int i =0; i < *returnColumnSizes[1]; i++)
    {
        printf("%d, ", answer[1][i]);
    }
    return 0;
}