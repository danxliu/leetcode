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

Node *helper(Node *node, set<Node *> &visited)
{
    if (node)
    {
        Node *next = new Node(node->val);
        for (auto &neighbor : node->neighbors)
        {
            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                next->neighbors.push_back(helper(neighbor, visited));
            }
        }
        return next;
    }
    return nullptr;
}

Node *cloneGraph(Node *node)
{
    set<Node *> visited;
    visited.insert(node);
    Node *head = helper(node, visited);
    return head;
}