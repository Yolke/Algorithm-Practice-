#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool hasPathSum(struct TreeNode *root, int targetSum)
{
  if(!root)
    return 0;
  targetSum -= root->val;
  return (!targetSum && !root->right && !root->left) ||
    hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

int main(){


    return 0;
}