#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode *root, int targetSum, int curSum)
{
    if (root == NULL)
        return false;
    else if (root->left == NULL && root->right == NULL)
    {
        curSum += root->val;
        if (curSum == targetSum)
            return true;
        return false;
    }
    else
    {
        bool left = dfs(root->left, targetSum, curSum + root->val);
        bool right = dfs(root->right, targetSum, curSum + root->val);
        return left || right;
    }
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    return dfs(root, targetSum, 0);
}

int main()
{
}