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

bool canPartition(vector<int> &nums)
{
    int tot = 0;
    for (int &i : nums)
        tot += i;
    if (tot % 2)
        return false;
    tot /= 2;
    int dp[nums.size() + 1][tot + 1];
    for (int i = 0; i <= nums.size(); i++)
        dp[i][0] = 0;
    for (int i = 0; i <= tot; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= nums.size(); i++)
    {
        for (int j = 0; j <= tot; j++)
        {
            if (j - nums[i - 1] >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[nums.size()][tot] == tot;
}

signed main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << canPartition(nums);
}