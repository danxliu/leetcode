#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
// #define int ll
#define FASTIO ios::sync_with_stdio(0), cin.tie(0);
#define endl "\n";

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

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    multiset<int> window;
    // create a window of size k
    for (int i = 0; i < nums.size(); i++)
    {
        if (window.size() >= k)
        {
            ans.push_back(*window.rbegin());
            window.erase(window.find(nums[i - k]));
        }
        window.insert(nums[i]);
    }
    ans.push_back(*window.rbegin());

    return ans;
}

signed main()
{
    // freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    maxSlidingWindow(nums, 3);
    return 0;
}