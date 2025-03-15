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

int missingNumber(vector<int> &nums)
{
    bool vis[nums.size() + 1];
    for (int i = 0; i <= nums.size(); i++)
        vis[i] = false;
    for (int &i : nums)
        vis[i] = true;
    for (int i = 0; i <= nums.size(); i++)
    {
        if (!vis[i])
            return i;
    }
    return -1;
}

signed main()
{
    vector<int> nums = {40, 43, 42, 18, 6, 13, 19, 8, 44, 4, 12, 22, 31, 30, 10, 16, 3, 17, 25, 7, 41, 21, 48, 26, 32, 27, 49, 15, 1, 20, 35, 46, 11, 23, 2, 0, 38, 28, 37, 9, 39, 47, 36, 45, 24, 34, 29, 14, 33};
    cout << missingNumber(nums);
}