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

map<pair<int, int>, double> dp;

double helper(int a, int b)
{
    cout << dp.size() << endl;
    if (a <= 0 && b <= 0)
    {
        return 0.5;
    }
    if (a <= 0)
    {
        return 1.0;
    }
    if (b <= 0)
    {
        return 0.0;
    }
    if (dp.find({a, b}) != dp.end())
    {
        return dp[{a, b}];
    }
    dp[{a, b}] = 0.25 * helper(a - 100, b) + 0.25 * helper(a - 75, b - 25) + 0.25 * helper(a - 50, b - 50) + 0.25 * helper(a - 25, b - 75);
    return dp[{a, b}];
}

double soupServings(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (helper(i, i) > 1 - 1e-5)
        {
            return 1;
        }
    }
    return helper(n, n);
}

signed main()
{
    cout << soupServings(660295675) << endl;
    for (auto it = dp.begin(); it != dp.end(); it++)
    {
        cout << it->first.first << " " << it->first.second << " " << it->second << endl;
    }
}