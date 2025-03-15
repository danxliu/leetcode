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

double findMaxAverage(vector<int> &nums, int k)
{
    int csum = 0;
    for (int i = 0; i < k; i++)
    {
        csum += nums[i];
    }
    double ans = (double)csum / k;
    for (int i = k; i < nums.size(); i++)
    {
        csum -= nums[i - k];
        csum += nums[i];
        ans = max(ans, (double)csum / k);
    }
    return ans;
}

signed main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    cout << findMaxAverage(nums, 4);
}