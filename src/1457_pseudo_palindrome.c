#include<stdio.h>
#include<stdlib.h>
/**
 * Definition for a binary tree node. */
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

void DFS_palindromepath(struct TreeNode* root, int **array, int *answer)
{
    int *freq_count = *array;
    if(root == NULL)
    {
        return;
    }
    freq_count[root->val]++;
    DFS_palindromepath(root->left, array, answer);
    DFS_palindromepath(root->right, array, answer);
    if(root->left == NULL && root->right == NULL)
    {
        int pairty_check = 0;
        for(int i = 0; i < 10; i++)
        {
            if(freq_count[i] & 1)
            {
                pairty_check++;
            }
        }
        if(pairty_check < 2)
        {
            (*answer)++;
        }
    }
    freq_count[root->val]--;
}
int pseudoPalindromicPaths (struct TreeNode* root) {
    int answer = 0;
    int freq_count[10] = {0};
    DFS_palindromepath(root, &freq_count, &answer);

    return answer;
}