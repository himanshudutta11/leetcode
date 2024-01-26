#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_PTS 40000
typedef struct node
{
    int pos;    /* current position */
    int dir;    /* current direction, 1 for forward and -1 for backward */
    int steps;  /* Number of steps taken */
    struct node* next;
}Jump_node;
Jump_node *create_node(int pos, int dir, int steps)
{
    Jump_node *node = (Jump_node *)malloc(sizeof(Jump_node));
    node->dir = dir;
    node->pos = pos;
    node->steps = steps;
    node->next = NULL;

    return node;
}
void enqueue(Jump_node **head, Jump_node **tail, Jump_node *node)
{
    if(*head == NULL)
    {
        *head = node;
        *tail = node;
    }
    else
    {
        (*tail)->next = node;
        *tail = node;
    }
}
Jump_node *dequeue(Jump_node **head, Jump_node **tail)
{
    if(*head == NULL)
    {
        return NULL;
    }
    Jump_node *node = *head;
    *head = (*head)->next;
    if(*head == NULL)
    {
        *tail = NULL;
    }
    return node;
}
bool isforbidden(int pos, int* forbidden, int forbiddenSize)
{
    for(int i = 0; i < forbiddenSize; i++)
    {
        if(forbidden[i] == pos)
        {
            return true;
        }
    }
    return false;
}
int minimumJumps(int* forbidden, int forbiddenSize, int a, int b, int x) {
    if(x == 0)
    {
        return 0;
    }

    bool visited[MAX_PTS][2];
    for(int i = 0; i < MAX_PTS; i++)
    {
        visited[i][0] = false;   /* forward direction */
        visited[i][1] = false;   /* backward direction */
    }

    for(int i = 0; i < forbiddenSize; i++)
    {
        visited[forbidden[i]][0] = true;
        visited[forbidden[i]][1] = true;
    }

    Jump_node *head = NULL;
    Jump_node *tail = NULL;

    enqueue(&head, &tail, create_node(0,0,0));

    visited[0][1] = true;

    while(head != NULL)
    {
        Jump_node *current = dequeue(&head, &tail);

        printf("----------------\n");

        printf("dequeue pos: %d dir: %d steps: %d\n", current->pos, current->dir, current->steps);

        if(current->pos == x)
        {
            return current->steps;
        }

        /* Try to jump forward */
        int next_pos = current->pos + a;
        int next_dir = 0;
        int next_steps = current->steps + 1;

        if(next_pos < MAX_PTS && visited[next_pos][next_dir] == false)
        {
            enqueue(&head, &tail, create_node(next_pos, next_dir, next_steps));
            visited[next_pos][next_dir] = true;
            printf("enqueue - pos: %d dir: %d steps: %d\n", next_pos, next_dir, next_steps);
        }

        /* Try to jump backward */
        next_pos = current->pos - b;
        next_dir = 1;
        next_steps = current->steps + 1;

        if(next_pos >= 0 && visited[next_pos][next_dir] == false && current->dir == 0)
        {
            enqueue(&head, &tail, create_node(next_pos, next_dir, next_steps));
            visited[next_pos][next_dir] = true;
            printf("enqueue - pos: %d dir: %d steps: %d\n", next_pos, next_dir, next_steps);
        }
        free(current);
    }
    return -1;
}
int main()
{
    // /* Test Case - 1 */
    // int forbidden[] = {14,4,18,1,15};
    // int a = 3;
    // int b = 15;
    // int x = 9;
    // int forbiddenSize = sizeof(forbidden)/sizeof(forbidden[0]);
    // printf("TC - 1: %d\n", minimumJumps(forbidden, forbiddenSize, a, b, x));

    // /* Test Case - 2 */
    // int forbidden_1[] = {8,3,16,6,12,20};
    // a = 15;
    // b = 13;
    // x = 11;
    // forbiddenSize = sizeof(forbidden_1)/sizeof(forbidden_1[0]);
    // printf("TC - 2: %d\n", minimumJumps(forbidden_1, forbiddenSize, a, b, x));


    // /* Test Case - 3 */
    // int forbidden_2[] = {1,6,2,14,5,17,4};
    // a = 16;
    // b = 9;
    // x = 7;
    // forbiddenSize = sizeof(forbidden_2)/sizeof(forbidden_2[0]);
    // printf("TC - 3: %d\n", minimumJumps(forbidden_2, forbiddenSize, a, b, x));

    int forbidden[] = {1998};
    int a = 1999;
    int b = 2000;
    int x = 2000;
    int forbiddenSize = sizeof(forbidden)/sizeof(forbidden[0]);
    printf("TC - 1: %d\n", minimumJumps(forbidden, forbiddenSize, a, b, x));

    return 0;
}
