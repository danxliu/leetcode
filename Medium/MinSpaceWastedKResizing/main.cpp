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

int minSpaceWastedKResizing(vector<int> &nums, int k)
{
    int dp[nums.size()][k + 1];
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = 1e6;
        }
    }
    for (int i = 0; i <= k; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int mx = 0, sum = 0;
            for (int l = i; l >= 0; --l)
            {
                sum += nums[l];
                mx = max(mx, nums[l]);
                if (i == 0 || j == 0)
                    dp[i][j] = mx * (i - l + 1) - sum;
                else if (l == 0)
                    dp[i][j] = min(dp[i][j], mx * (i - l + 1) - sum);
                else
                    dp[i][j] = min(dp[i][j], mx * (i - l + 1) - sum + dp[l - 1][j - 1]);
            }
        }
    }
    return dp[nums.size() - 1][k];
}

signed main()
{
    vector<int> nums = {5, 7, 15, 30};
    cout << minSpaceWastedKResizing(nums, 0);
}