#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode *root, int depth)
{
    if (root->left == NULL && root->right == NULL)
    {
        return depth;
    }
    else
    {
        int left = 0;
        int right = 0;
        if (root->left != NULL)
        {
            left = dfs(root->left, depth + 1);
        }
        if (root->right != NULL)
        {
            right = dfs(root->right, depth + 1);
        }
        return max(left, right);
    }
}

int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return dfs(root, 0) + 1;
}

int main()
{
}