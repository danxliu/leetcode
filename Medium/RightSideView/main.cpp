#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define FASTIO ios::sync_with_stdio(0), cin.tie(0);
// --------------------Leetcode-Data-Structures--------------------------

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helper(TreeNode *root, vector<int> &ans, int depth)
{
    if (root == nullptr)
    {
        return;
    }
    if (depth >= ans.size())
    {
        ans.push_back(root->val);
    }
    helper(root->right, ans, depth + 1);
    helper(root->left, ans, depth + 1);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    helper(root, ans, 0);
    return ans;
}

int main()
{
}