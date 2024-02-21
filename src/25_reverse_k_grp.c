/**
 * Definition for singly-linked list.
 */
#include<stdio.h>
#include<stdlib.h>
struct ListNode{
     int val;
     struct ListNode *next;
};
struct ListNode * addNode(int val)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* cur = head;
    int num = 0;
    while(cur != NULL)
    {
        num++;
        cur = cur->next;
    }
    int total = (num - num % k) / k;
    cur = head;
    struct ListNode* prev = NULL;
    for(int i = 0; i < total; i++)
    {
        int each = 0;
        while(each < k)
        {
            prev = cur;
            cur = cur->next;
            cur->next = prev;
            each++;
        }
        if(i == 0)
        {
            head = prev;
        }
    }
    return head;
}
int main()
{
    struct ListNode *list = addNode(1);
    list->next = addNode(2);
    list->next->next = addNode(3);
    list->next->next->next = addNode(4);
    list->next->next->next->next = addNode(5);

    list = reverseKGroup(list, 2);

    struct ListNode *cur = list;

    while(cur != NULL)
    {
        printf("%d, ", cur->val);
        cur = cur->next;
    } 
}