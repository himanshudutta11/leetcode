/**
 * Definition for singly-linked list.*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct ListNode {
      int val;
      struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *p = head;
    struct ListNode *q = head;
    if(head == NULL)
    {
        return false;
    }
    if(head->next == NULL)
    {
        return false;
    }
    /*
    do{
        p = p->next;
        q = q->next;
        if(q)
        {
            q = q->next;
        }

    }while(p != NULL && q != NULL && p != q);

    if(p == q)
    {
        return true;
    }
    else
    {
        return false;
    }*/


    q = head->next;
    while(p != q)
    {
        if(q == NULL)
        {
            return false;
        }
        p = p->next;
        q = q->next->next;
    }
    return true;

}
struct ListNode *add_node(int val)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
int main()
{
    struct ListNode *list = add_node(3);
    list->next = add_node(2);
    list->next->next = add_node(0);
    list->next->next->next = add_node(4);
    list->next->next->next->next = list->next;

    printf("hascycle = %d \n", hasCycle(list));


    return 0;
}