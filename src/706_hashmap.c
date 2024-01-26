#include<stdio.h>
#include<stdlib.h>
typedef struct HashMap{
    int key;
    int value;
    struct HashMap *next;    
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap *node = (MyHashMap *)malloc(sizeof(MyHashMap));
    node->next = NULL;
    return node;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    printf("obj: 0x%x\n", obj);
    while(obj->next != NULL)
    {
        obj = obj->next;
    }
    MyHashMap *node = (MyHashMap *)malloc(sizeof(MyHashMap));
    node->key = key;
    node->value = value;
    node->next = NULL;
    obj->next = node;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int count = 0;
    while(obj != NULL)
    {
        if(obj->key == key)
        {
            return count;
        }
        count++;
        obj = obj->next;
        printf("count: %d\n", count);
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    printf("myHashMapRemove\n");
    while(obj->next != NULL)
    {

        printf("obj: 0x%x, obj->next: %x\n", obj, obj->next);
        printf("obj->key: 0x%x, obj->next: %d\n", obj->key, obj->next->key);
        if(obj->next->key == key)
        {
            obj->next = obj->next->next;
            free(obj->next);
            return;
        }
        else
        {
            obj = obj->next;
        }
    }
}

void myHashMapFree(MyHashMap* obj) {
    if(obj == NULL)
    {
        free(obj);
        return;
    }
    else
    {
        myHashMapFree(obj->next);
    }
}
int main()
{
    printf("Creating the hashmap\n");
    MyHashMap* obj = myHashMapCreate();
    printf("Created the hashmap\n");
    printf("Putting 1,1 to the hashmap\n");
    myHashMapPut(obj, 1, 1);
    printf("1,1 is placed to the hashmap\n");
    myHashMapPut(obj, 2, 2);
 
    int param_2 = myHashMapGet(obj, 1);

    printf("%d\n", param_2);
 
    param_2 = myHashMapGet(obj, 3);

    printf("%d\n", param_2);

    myHashMapPut(obj, 2, 1);

    param_2 = myHashMapGet(obj, 2);

    printf("%d\n", param_2);

    myHashMapRemove(obj, 2);

    param_2 = myHashMapGet(obj, 2);

    printf("%d\n", param_2);

    printf("1 is removed from the hashmap\n");

    myHashMapFree(obj);

    return 0;
 
 }