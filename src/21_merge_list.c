#include<stdio.h>
#include<stdlib.h>
 /* Definition for singly-linked list.
 */
struct ListNode {
  int val;
  struct ListNode *next;
};
struct ListNode *createNode(int val)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
void printfList(struct ListNode *list)
{
    while(list)
    {
        printf("%d,", list->val);
        list = list->next;
    }
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = NULL;
    if(list1 != NULL && list2 != NULL)
    {
        if(list1->val < list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }
    }
    else if(list2 == NULL)
    {
        return list1;
    }
    else if(list1 == NULL)
    {
        return list2;
    }
    struct ListNode* t = head;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val < list2->val)
        {
            t->next = list1;
            list1 = list1->next; 
        }
        else
        {
            t->next = list2;
            list2 = list2->next;
        }
        t = t->next;
    }
    if(list1) t->next = list1;
    if(list2) t->next = list2;

    return head;
}
int main()
{
    struct ListNode *list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);
    struct ListNode *list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);
    list1 = mergeTwoLists(list1, list2);
    printfList(list1);

    return 0;
}