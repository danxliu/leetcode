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

void parseTree(TreeNode *root, priority_queue<int> &q)
{
    q.push(root->val);
    if (root->left)
        parseTree(root->left, q);
    if (root->right)
        parseTree(root->right, q);
}

int kthSmallest(TreeNode *root, int k)
{
    priority_queue<int> q;
    parseTree(root, q);
    while (k--)
    {
        q.pop();
    }
    return q.top();
}

signed main()
{
}