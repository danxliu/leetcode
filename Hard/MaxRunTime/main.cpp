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

bool helper(int n, vector<int> &batteries, long long t)
{
    long long extra = 0;
    auto it = lower_bound(batteries.begin(), batteries.end(), t);
    int remaining = it - batteries.begin();
    if (batteries.size() - remaining >= n)
    {
        return true;
    }
    for (int i = 0; i < remaining; i++)
    {
        extra += batteries[i];
    }
    n -= batteries.size() - remaining;
    if (extra >= n * t)
    {
        return true;
    }
    return false;
}

long long maxRunTime(int n, vector<int> &batteries)
{
    sort(batteries.begin(), batteries.end());
    // binary search for answer
    long long low = 0;
    long long high = LLONG_MAX - 1;
    while (low < high)
    {
        long long mid = (low + high + 1) / 2;
        if (helper(n, batteries, mid))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

signed main()
{
    vector<int> batteries = {1, 1, 1, 1};
    cout << maxRunTime(2, batteries);
}