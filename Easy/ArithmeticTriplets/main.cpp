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

int arithmeticTriplets(vector<int> &nums, int diff)
{
    int ans = 0;
    for (int i = 0; i < nums.size() - 2; i++)
        for (int j = i + 1; j < nums.size() - 1 && nums[j] <= nums[i] + diff; j++)
            for (int k = j + 1; k < nums.size() && nums[k] <= nums[j] + diff; k++)
                if (nums[k] - nums[j] == diff && nums[j] - nums[i] == diff)
                    ans++;
    return ans;
}

signed main()
{
    vector<int> nums = {4, 5, 6, 7, 8, 9};
    cout << arithmeticTriplets(nums, 2);
}