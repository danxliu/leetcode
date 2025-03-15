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

int check(vector<int> &nums, int p, int mx)
{
    int cp = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - nums[i - 1] <= mx)
        {
            cp++;
            i++;
        }
        if (cp >= p)
            return true;
    }
    return cp == p;
}

int minimizeMax(vector<int> &nums, int p)
{
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = nums.back();
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(nums, p, mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

signed main()
{
    vector<int> nums = {1};
    cout << minimizeMax(nums, 0);
}