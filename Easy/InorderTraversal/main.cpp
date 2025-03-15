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

void helper(TreeNode *root, vector<int> &arr)
{
    if (!root)
    {
        return;
    }
    if (root->left)
    {
        helper(root->left, arr);
    }
    arr.push_back(root->val);
    if (root->right)
    {
        helper(root->right, arr);
    }
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    helper(root, ans);
    return ans;
}

signed main()
{
}