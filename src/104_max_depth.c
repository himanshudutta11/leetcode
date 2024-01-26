#include<stdio.h>
#include<stdlib.h>
/**
 * Definition for a binary tree node.*/
#define MAX(A,B) (A>B)?A:B
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};
 
int maxDepth(struct TreeNode* root) {
    if(root == NULL)
    {
        return 0;
    }
    
    int maxdepthleft = 0;

    int maxdepthright = 0;

    int max = 0;

    if(root->left || root->right)
    {
        maxdepthleft = maxDepth(root->left);
        maxdepthright = maxDepth(root->right);
        printf("maxdepthleft: %d maxdepthright: %d\n", maxdepthleft, maxdepthright);
        //max = MAX(maxdepthleft, maxdepthright);
    }

    return MAX(maxdepthleft, maxdepthright) + 1;

}
struct TreeNode *Add_Node(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->val = val;
    return node;
}
int main()
{
    struct TreeNode *tree = Add_Node(1);
    tree->left = Add_Node(1);

    printf("Maxdepth: %d", maxDepth(tree));

    return 0;
}