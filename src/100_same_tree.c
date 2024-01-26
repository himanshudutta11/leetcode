#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
struct TreeNode *create_tree_node(int val)
{
    struct TreeNode *tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    tree->val = val;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(!p && !q)
    {
        return true;
    }
    if(!p || !q)
    {
        return false;
    }
    if(p->val = q->val)
    {
        return false;
    }
    return isSameTree(p->left, q->left);
    return isSameTree(p->right, q->right);
}
int main()
{
    struct TreeNode *tree_1 = create_tree_node(10);
    tree_1->left =  create_tree_node(5);
    tree_1->right =  create_tree_node(15);

    struct TreeNode *tree_2 = create_tree_node(10);
    tree_2->left =  create_tree_node(5);
    tree_2->left->right =  create_tree_node(15);


    printf("isSameTree: %d", isSameTree(tree_1, tree_2));
    return 0;
}