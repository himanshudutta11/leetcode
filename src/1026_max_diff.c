#include<stdio.h>
#include<stdlib.h>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
struct TreeNode *add_Node(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
/*
void minmaxtree(struct TreeNode *root, int *min, int *max)
{
    if(root->val > *max)
    {
        *max = root->val;
    }
    if(root->val < *min)
    {
        *min = root->val;
    }
    if(root->left != NULL)
    {
        minmaxtree(root->left, min, max);
    }
    if(root->right != NULL)
    {
        minmaxtree(root->right, min, max);
    }
    printf("*min: %d *max: %d\n", *min, *max);
} 
int maxAncestorDiff(struct TreeNode* root) {
    int min = root->val;
    int max = root->val;
    
    if(root->left)
    {
        minmaxtree(root->left, &min, &max);    
    }
    int v_left = (max > min)?max-min:min-max;
    min = root->val;
    max = root->val;
    if(root->right)
    {
        minmaxtree(root->right, &min, &max);
    }
    int v_right = (max > min)?max-min:min-max;
    int v = (v_left > v_right)? v_left: v_right;
    return v;    
}*/
int maxAncestorDiff_rec(struct TreeNode* root, int min, int max) {
    if(root == NULL)
    {
        return 0;
    }
    min = (root->val < min)?root->val:min;
    max = (root->val > max)?root->val:max;
    int left = maxAncestorDiff_rec(root->left, min, max);
    int right = maxAncestorDiff_rec(root->right, min, max);
    return ((max - min) > left)?((max - min) > right?(max - min):right):(left > right?left:right);
}

int maxAncestorDiff(struct TreeNode* root) {
    maxAncestorDiff_rec(root, root->val, root->val);
}
/*
int main()
{
    struct TreeNode *root = add_Node(8);
    root->left = add_Node(3);
    root->right = add_Node(10);
    root->left->left = add_Node(1);
    root->left->right = add_Node(6);
    root->left->right->left = add_Node(4);
    root->left->right->right = add_Node(7);
    root->right->right = add_Node(14);
    root->right->right->left = add_Node(13);

    printf("%d", maxAncestorDiff(root));

    return 0;

}*/
int main()
{
    struct TreeNode *root = add_Node(2);
    root->left = add_Node(4);
    root->right = add_Node(3);
    root->left->left = add_Node(1);
    root->right->left = add_Node(0);
    root->right->right = add_Node(5);
    root->left->left->right = add_Node(6);
    root->right->right->right = add_Node(7);

    printf("%d", maxAncestorDiff(root));

    return 0;

}