#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define HASH_SIZE 100
#define HASH_CODE(v) ((unsigned int)v % HASH_SIZE)
typedef struct item{
    int val;
    struct item *shadow;
}Item;
typedef struct randomizedSet{
    Item *item_list[100];
    int num;
} RandomizedSet;

RandomizedSet* randomizedSetCreate() {
    RandomizedSet* set = (RandomizedSet*)calloc(1, sizeof(RandomizedSet));
    return set;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    Item *e = obj->item_list[HASH_CODE(val)];
    while(e && e->val != val)
    {
        e = e->shadow;
    }
    if(e)
    {
        return false;
    }
    e = (Item *)calloc(1, sizeof(Item));
    e->val = val;
    e->shadow = obj->item_list[HASH_CODE(val)];
    obj->item_list[HASH_CODE(val)] = e;
    obj->num++;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    Item **head = &obj->item_list[HASH_CODE(val)];;
    Item *e = *head;
    while(e && e->val != val)
    {
        head = &e->shadow;
        e = *head;
    }
    if(!e)
    {
        return false;
    }
    *head = e->shadow;
    obj->num--;
    free(e);
    return true;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    int j = random() % obj->num;
    int i = 0;
    if(obj->num == 0) return -1;
    Item *e = NULL;
    while(!e && i < HASH_SIZE && j >= 0)
    {
        e = obj->item_list[i];
        while(e && j > 0)
        {
            e = e->shadow;
            j--;
        }
        i++;
    }
    return e->val;
}

void randomizedSetFree(RandomizedSet* obj) {
    Item *e, *f;
    for(int i = 0; i < HASH_SIZE; i++)
    {
        e = obj->item_list[i];
        while(e)
        {
            f = e->shadow;
            free(e);
            e = f;
        }
    }
    free(obj);
}
int main()
{
    RandomizedSet* set = randomizedSetCreate();
    printf("%d, ",  randomizedSetInsert(set, 1));
    printf("%d, ",  randomizedSetRemove(set, 2));
    printf("%d, ",  randomizedSetInsert(set, 2));
    printf("%d, ",  randomizedSetGetRandom(set)); 
    printf("%d, ",  randomizedSetRemove(set, 1)); 
    printf("%d, ",  randomizedSetInsert(set, 2)); 
    printf("%d, ",  randomizedSetGetRandom(set));

    return 0;
}