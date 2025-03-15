#include <bits/stdc++.h>
using namespace std;

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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// --------------------Snippet-Ends--------------------------------

void helper(int &n, int &k, vector<vector<int>> &ans, vector<int> &cur, int i)
{
    if (cur.size() == k)
    {
        ans.push_back(cur);
        return;
    }
    for (int j = i; j <= n; j++)
    {
        cur.push_back(j);
        helper(n, k, ans, cur, j + 1);
        cur.pop_back();
    }
    return;
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> cur;
    helper(n, k, ans, cur, 1);
    return ans;
}

signed main()
{
    vector<vector<int>> ans = combine(4, 2);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}