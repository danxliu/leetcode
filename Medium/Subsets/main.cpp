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

vector<vector<int>> subsets(vector<int> &nums)
{
    // gonna use bitmasks cuz im cool :DDDDD
    vector<vector<int>> ans;
    vector<int> cur;
    for (int i = 0; i < (1 << nums.size()); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if ((i >> j) & 1)
                cur.push_back(nums[j]);
        }
        ans.push_back(cur);
        cur.clear();
    }
    return ans;
}

signed main()
{
    vector<int> nums = {1, 2, 3};
    subsets(nums);
}