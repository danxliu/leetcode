#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
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

// --------------------Snippet-Ends--------------------------------

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < nums.size(); i++)
    {
        q.push(nums[i]);
        if (q.size() > k)
        {
            q.pop();
        }
    }
    return q.top();
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << findKthLargest(nums, 2);
}