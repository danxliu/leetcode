#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define FASTIO ios::sync_with_stdio(0), cin.tie(0);
// --------------------Leetcode-Data-Structures--------------------

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// --------------------Snippet-Ends--------------------------------

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    q.push(root);
    ans.push_back({root->val});
    while (!q.empty())
    {
        vector<TreeNode *> layer;
        for (int i = 0; i < q.size(); i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left)
                layer.push_back(cur->left);
            if (cur->right)
                layer.push_back(cur->right);
        }
        if (layer.size())
            ans.push_back({});
        for (int i = 0; i < layer.size(); i--)
        {
            ans.back().push_back(layer[i]->val);
            q.push(layer[i]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i % 2 == 0)
        {
            reverse(ans[i].begin(), ans[i].end());
        }
    }
    return ans;
}