#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
/**
 * Definition for a Node. */
struct Node{
  int val;
  int numNeighbors;
  struct Node** neighbors;
};

int hash_map[100] = {0};

struct Queue{
    int front;
    int end;
    struct Node *arr[SIZE];
};

struct Queue queue_bfs;
struct Queue *queue_bfs_ptr = &queue_bfs;

void enqueue(struct Queue *q, struct Node *data_node)
{
  if (q->end == q->front)
  {
    printf("Queue is full\n");
  }
  else
  {
    if(q->front = -1) q->front = 0;
    q->end = (q->end + 1) % SIZE;
    q->arr[q->end] = data_node;
  }
}

struct Node *dequeue(struct Queue *q)
{
  struct Node *data_node = NULL;
  if(q->front > q->end || q->front == -1)
  {
      printf("Queue is emepty");
  }
  else
  {
    data_node = q->arr[q->front];
    q->front = q->front+1;
  }
  return data_node;
}

void recursive_enqueue(struct Node *s)
{
  if(s != NULL)
  {
      enqueue(queue_bfs_ptr, s);
      for(int i = 0; i < s->numNeighbors; i++)
      {
          recursive_enqueue(s->neighbors[i]);
      }
  }
}

struct Node* recursive_dequeue()
{
    struct Node *ret_data = dequeue(queue_bfs_ptr);
    if(hash_map[ret_data->val] == 0)
    {
      hash_map[ret_data->val] = 1;
      struct Node *new_node = (struct Node *)calloc(1, sizeof(struct Node));
      new_node->val = ret_data->val;
      new_node->numNeighbors = ret_data->numNeighbors;
      new_node->neighbors = (struct Node**)calloc(new_node->numNeighbors, sizeof(struct Node*));
      for(int i = 0; i < new_node->numNeighbors; i++)
      {
          new_node->neighbors[i] = recursive_dequeue();
      }
    }
    return ret_data;
}

struct Node *cloneGraph(struct Node *s) {
  if(s == NULL) return s;

  recursive_enqueue(s);

  struct Node* head = recursive_dequeue();
  
  return head;
}
int main()
{
    struct Node *graph = NULL;

    queue_bfs_ptr->front = -1;
    queue_bfs_ptr->end = -1;

    cloneGraph(graph);
    return 0;
}