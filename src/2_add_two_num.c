#include <stdio.h>
#include <stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
 };
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *num1 = l1;
    struct ListNode *num2 = l2;
    int carry = 0;
    struct ListNode *head = NULL;
    struct ListNode *prev = head;
    while(num1 || num2)
    {
        struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->next = NULL;
        if(num1 && num2)
        {
            new->val = (num1->val + num2->val + carry)%10;
            carry = (num1->val + num2->val + carry)/10;
            num1 = num1->next;
            num2 = num2->next;
        }
        else if(num1)
        {
            new->val = (num1->val + carry)%10;
            carry = (num1->val + carry)/10;
            num1 = num1->next;
        }
        else if(num2)
        {
            new->val = (num2->val + carry)%10;
            carry = (num2->val + carry)/10;
            num2 = num2->next;
        }
        if(prev == NULL)
        {
            head = new;
            prev = head;
        }
        else
        {
            prev->next = new;
            prev = new;
        }
    }
    if(carry != 0)
    {
        struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->next = NULL;
        new->val = carry;
        prev->next = new;
    }
    return head;
}
/*
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *temp;
    struct ListNode *sum = NULL;  
    int num1 = 0;
    int num2 = 0;
    temp = l1;
    int n = 0;
    int i = 0;
    while (temp != NULL) {
        num1 = num1 + (temp->val * mypow(10, i));
        i++;
        temp = temp->next;
    }
    temp = l2;
    i = 0;
    while (temp != NULL) {
        num2 = num2 + (temp->val * mypow(10, i));
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
       new->val = add / mypow(10, (i - 1));
       new->next = sum;
       i--;
       add = add % (int)(mypow(10, i));
       sum = new;
    }
    return sum;
}*/
struct ListNode *createNumber(int n, const int vals[n])
{
    if(n == 0)
    {
        return NULL;
    }
    struct ListNode *head = NULL;
    struct ListNode *prev = head;
    for(int i = 0; i < n; i++)
    {
        struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newnode->val = vals[i];
        newnode->next = NULL;
        if(prev == NULL)
        {
            head = newnode;
            prev = head;
        }
        else
        {
            prev->next = newnode;
            prev = newnode;
        }
    }
    return head;
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
    printNumber(addTwoNumbers(createNumber(2, (int[]){5,6}), createNumber(3, (int[]){5,4,9})));
}