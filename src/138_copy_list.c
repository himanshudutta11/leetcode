
/* *
 * Definition for a Node. */
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};


struct Node* copyRandomList(struct Node* head)
{
    if(head == NULL) return NULL;

    struct Node *new_node = NULL;
    struct Node *pnode = head;

    while(pnode)
    {
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->val = pnode->val;
        new_node->next = pnode->next;
        pnode->next = new_node;
        pnode = new_node->next;
    }

    pnode = head;

    struct Node *new_head = pnode->next;
    struct Node *qnode = NULL;

    while(pnode)
    {
        qnode = pnode->next;
        if(pnode->random == NULL)
        {
            qnode->random = NULL;
        }
        else
        {
            qnode->random = pnode->random->next;
        }
        pnode = qnode->next;
    }

    pnode = head;

    while(pnode)
    {
        qnode = pnode->next;
        pnode->next = qnode->next;
        pnode = pnode->next;

        if(pnode)
        {
            qnode->next = pnode->next;
        }
        else
        {
            qnode->next = NULL;
        }
    }
    return new_head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(4*sizeof(struct Node));

     head->val = 1;
    (head+1)->val = 2;
    (head+2)->val = 3;
    (head+3)->val = 4;

    head->next = head + 1;
    (head+1)->next = head + 2;
    (head+2)->next = head + 3;
    (head+3)->next = NULL;

    head->random = head + 3;
    (head+1)->random = head;
    (head+2)->random = NULL;
    (head+3)->random = head+3;

    struct Node *p = head;

    printf("N\tR\n");
    while(p)
    {
        printf("%d\t", p->val);
        if(p->random)
        {
            printf("%d\n", p->random->val);
        }
        else
        {
            printf("NIL\n");
        }

        p = p->next;
    }

    struct Node *new_node = copyRandomList(head);

    p = new_node;

    printf("After copy\n");

    printf("N\tR\n");
    while(p)
    {
        printf("%d\t", p->val);
        if(p->random)
        {
            printf("%d\n", p->random->val);
        }
        else
        {
            printf("NIL\n");
        }

        p = p->next;
    }

    struct Node *new = copyRandomList(head);


    return 0;
}