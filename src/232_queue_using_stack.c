#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct StackNode{
    int val;
    struct StackNode* next;
};

struct Stack{
    struct StackNode* top;
};

void push(struct Stack* stack, int val)
{
    if(stack == NULL)
    {
        return;
    }

    struct StackNode* new_node = (struct StackNode*)malloc(sizeof(struct StackNode));

    new_node->val = val;
    new_node->next = stack->top;

    stack->top = new_node;
}

int pop(struct Stack* stack)
{
    if(stack == NULL || stack->top == NULL)
    {
        return -1;
    }
    struct StackNode* top = stack->top;
    int ans = top->val;

    stack->top = stack->top->next;
    free(top);

    return ans;
}

bool isEmpty(struct Stack* stack)
{
    if(stack == NULL) return true;

    return (stack->top == NULL)? true:false;
}

typedef struct {
    struct Stack in;
    struct Stack out;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->in.top = queue->out.top = NULL;

    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    if(obj == NULL) return;

    while(!isEmpty(&obj->out))
    {
        int top = pop(&obj->out);
        push(&obj->in, top);
    }
    push(&obj->in, x);
}

int myQueuePop(MyQueue* obj) {
    if(obj == NULL) return -1;
    
    if(isEmpty(&obj->out))
    {
        while(!isEmpty(&obj->in))
        {
            int top = pop(&obj->in);
            push(&obj->out, top);
        }
    }
    return pop(&obj->out);
}

int myQueuePeek(MyQueue* obj) {
    if(isEmpty(&obj->out))
    {
        while(!isEmpty(&obj->in))
        {
            int top = pop(&obj->in);
            push(&obj->out, top);
        }
    }
    if(!isEmpty(&obj->out) && obj->out.top)
    {
        return obj->out.top->val;
    }
    else
    {
        return -1;
    }
}

bool myQueueEmpty(MyQueue* obj) {
    if(isEmpty(&obj->in) && isEmpty(&obj->out))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void myQueueFree(MyQueue* obj) {

    while(!isEmpty(&obj->in))
    {
        pop(&obj->in);
    }
    while(!isEmpty(&obj->out))
    {
        pop(&obj->out);
    }    
}
int main()
{
    MyQueue *queue = myQueueCreate();
    printf("Push 1\n");
    myQueuePush(queue, 1);
    printf("Push 2\n");
    myQueuePush(queue, 2);
    printf("Push 3\n");
    myQueuePush(queue, 3);
    printf("Push 4\n");
    myQueuePush(queue, 4);

    printf("Pop %d\n", myQueuePop(queue));

    myQueuePush(queue, 5);
    printf("Push 5\n");

    printf("Pop %d\n", myQueuePop(queue));
    printf("Pop %d\n", myQueuePop(queue));
    printf("Pop %d\n", myQueuePop(queue));

    return 0;
}
/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
