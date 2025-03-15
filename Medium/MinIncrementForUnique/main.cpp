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

int minIncrementForUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int ans = 0;
    vector<int> duplicates;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            duplicates.push_back(nums[i]);
        }
        else if (nums[i] > nums[i - 1] + 1)
        {
            for (int j = nums[i - 1] + 1; j < nums[i] && duplicates.size(); j++)
            {
                ans += j - duplicates.back();
                duplicates.pop_back();
            }
        }
    }
    for (int i = nums.back() + 1; duplicates.size(); i++)
    {
        ans += i - duplicates.back();
        duplicates.pop_back();
    }
    return ans;
}

signed main()
{
    vector<int> nums = {3, 2, 1, 2, 1, 7};
    cout << minIncrementForUnique(nums);
}