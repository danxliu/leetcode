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

vector<double> averageOfLevels(TreeNode *root)
{
    vector<double> ans;
    vector<int> sz;
    queue<pair<TreeNode *, int>> q; // stores treenode and depth
    q.push({root, 0});
    while (!q.empty())
    {
        TreeNode *curNode = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (ans.size() <= depth)
        {
            ans.push_back(curNode->val);
            sz.push_back(1);
        }
        else
        {
            ans[ans.size() - 1] += curNode->val;
            sz[sz.size() - 1]++;
        }

        q.push({curNode->left, depth + 1});
        q.push({curNode->right, depth + 1});
    }
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] /= (double)sz[i];
    }
    return ans;
}