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

int maximumJumps(vector<int> &nums, int target)
{
    vector<int> dp;
    dp.assign(nums.size(), -1);
    dp[0] = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (abs(nums[j] - nums[i]) <= target && dp[j] != -1)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (int &i : dp)
        cout << i << " ";
    cout << endl;
    return dp.back();
}

signed main()
{
    vector<int> nums = {0, 2, 1, 3};
    cout << maximumJumps(nums, 1);
}