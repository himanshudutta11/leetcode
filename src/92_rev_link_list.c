#include<stdio.h>
#include<stdlib.h>
/**
 * Definition for singly-linked list.*/
struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    int index = 1;
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while(index != left)
    {
        prev = cur;
        cur = cur->next;
        index++;
    }
    struct ListNode* prev_temp = prev;
    struct ListNode* post_temp = cur;
    while(index != right)
    {
        struct ListNode* t = cur->next;
        cur->next = prev;
        prev = cur;
        cur = t;
        index++;
    }
    post_temp->next = cur->next;
    cur->next = prev;
    prev_temp->next = cur;

    return head;
}
struct ListNode *add_node(int val)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
void print_list(struct ListNode *list)
{
    while(list != NULL)
    {
        printf("%d ,",list->val);
        list = list->next;
    }
}
int main()
{
    // struct ListNode *list = add_node(1);
    // list->next = add_node(2);
    // list->next->next = add_node(3);
    // list->next->next->next = add_node(4);
    // list->next->next->next->next = add_node(5);
    struct ListNode *list = add_node(3);
    list->next = add_node(5);
    list = reverseBetween(list, 1, 1);

    print_list(list);
}