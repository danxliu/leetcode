#include <iostream>
#include <queue>
#include <algorithm>
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

pair<int, int> dfs(TreeNode *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }
    pair<int, int> left = dfs(root->left);
    pair<int, int> right = dfs(root->right);
    return {root->val + left.second + right.second, max(left.first, left.second) + max(right.first, right.second)};
}

int rob(TreeNode *root)
{
    pair<int, int> ans = dfs(root);
    return max(ans.first, ans.second);
}

int main()
{
}