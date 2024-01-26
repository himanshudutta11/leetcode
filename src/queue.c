#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
/**
 * Definition for a Node. */

struct Queue{
    int front;
    int end;
    int arr[SIZE];
};


void enqueue(struct Queue *q, int data)
{
  if (q->end == q->front)
  {
    printf("Queue is full\n");
  }
  else
  {
    if(q->front = -1) q->front = 0;
    q->end = (q->end + 1) % SIZE;
    q->arr[q->end] = data;
  }
}

int dequeue(struct Queue *q)
{
  int data = 0;
  if(q->front > q->end || q->front == -1)
  {
      printf("Queue is emepty");
  }
  else
  {
    data = q->arr[q->front];
    q->front = q->front+1;
  }
  return data;
}

int main()
{
    struct Queue queue_bfs;
    struct Queue *queue_bfs_ptr = &queue_bfs;

    queue_bfs.front = -1;
    queue_bfs.end = -1;
    enqueue(queue_bfs_ptr, 2);
    return 0;
}