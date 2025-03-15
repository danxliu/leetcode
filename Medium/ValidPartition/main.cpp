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

map<int, bool> dp;

bool helper(int i, vector<int> &nums)
{
    if (i < 0)
        return true;
    bool ans = false;
    if (dp.count(i))
        return dp[i];
    if (i >= 1 && nums[i] == nums[i - 1])
        ans = ans || helper(i - 2, nums);
    if (i >= 2 && nums[i] == nums[i - 1] && nums[i - 2] == nums[i - 1])
        ans = ans || helper(i - 3, nums);
    if (i >= 2 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1)
        ans = ans || helper(i - 3, nums);
    dp[i] = ans;
    return ans;
}

bool validPartition(vector<int> &nums)
{
    return helper(nums.size() - 1, nums);
}

signed main()
{
    vector<int> nums = {1, 1, 1, 2};
    cout << validPartition(nums);
}