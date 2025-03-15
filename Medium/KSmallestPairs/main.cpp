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

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n = nums1.size();
    int m = nums2.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    set<pair<int, int>> visited;
    vector<vector<int>> ans;
    visited.insert({0, 0});
    pq.push({nums1[0] + nums2[0], {0, 0}});
    while (!pq.empty() && ans.size() < k)
    {
        auto cur = pq.top();
        pq.pop();
        ans.push_back({nums1[cur.second.first], nums2[cur.second.second]});
        if (cur.second.first + 1 < n && visited.find({cur.second.first + 1, cur.second.second}) == visited.end())
        {
            visited.insert({cur.second.first + 1, cur.second.second});
            pq.push({nums1[cur.second.first + 1] + nums2[cur.second.second], {cur.second.first + 1, cur.second.second}});
        }
        if (cur.second.second + 1 < m && visited.find({cur.second.first, cur.second.second + 1}) == visited.end())
        {
            visited.insert({cur.second.first, cur.second.second + 1});
            pq.push({nums1[cur.second.first] + nums2[cur.second.second + 1], {cur.second.first, cur.second.second + 1}});
        }
    }
    return ans;
}

signed main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3};
    vector<vector<int>> ans = kSmallestPairs(nums1, nums2, 3);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}