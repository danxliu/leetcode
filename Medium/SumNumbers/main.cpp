#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
// #define int ll
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
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

// --------------------Snippet-Ends--------------------------------

void helper(TreeNode *root, int cur, int &ans)
{
    if (!root->left && !root->right)
    {
        ans += cur;
        return;
    }
    cur = cur * 10 + root->val;
    if (root->left)
        helper(root->left, cur, ans);
    if (root->right)
        helper(root->right, cur, ans);
}

int sumNumbers(TreeNode *root)
{
    int ans = 0;
    helper(root, 0, ans);
    return ans;
}

signed main()
{
}