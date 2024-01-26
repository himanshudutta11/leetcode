#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Definition for singly-linked list.
struct ListNode {
      int val;
      struct ListNode *next;
 };
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *temp;
    struct ListNode *sum = NULL;  
    int num1 = 0;
    int num2 = 0;
    temp = l1;
    int n = 0;
    int i = 0;
    while (temp != NULL) {
        num1 = num1 + (temp->val * pow(10, i));
        i++;
        temp = temp->next;
    }
    temp = l2;
    i = 0;
    while (temp != NULL) {
        num2 = num2 + (temp->val * pow(10, i));
        i++;
        temp = temp->next;
    }
    int add = num1 + num2;
    int tem = add;
    i = 0;
    for (i = 0; tem > 0; i++) {
        tem = tem / 10;
    }
    if (add == 0) {
       struct ListNode *new = malloc(sizeof(struct ListNode));  
       new->val = 0;
       new->next = sum;
       sum = new;
    }
    while (add > 0 && i > 0) {
       struct ListNode *new = malloc(sizeof(struct ListNode));  
       new->val = add / pow(10, (i - 1));
       new->next = sum;
       i--;
       add = add % (int)(pow(10, i));
       sum = new;
    }
    return sum;
}
struct ListNode *createNumber(int n, const int vals[n])
{
    if(n == 0)
    {
        return NULL;
    }
    struct ListNode *tail = NULL;
    for(int i = 0; i < n; i++)
    {
        struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newnode->val = vals[i];
        newnode->next = tail;
        tail = newnode;
    }
    return tail;
} 
void printNumber2(const struct ListNode *n)
{
    if(!n) return;
    printNumber2(n->next);
    printf("%d", n->val);
}
void printNumber(const struct ListNode *n)
{
    printNumber2(n);
    printf("\n");
}
int main()
{
    printNumber(addTwoNumbers(createNumber(1, (int[]){9}), createNumber(4, (int[]){9,9,9,9})));
}