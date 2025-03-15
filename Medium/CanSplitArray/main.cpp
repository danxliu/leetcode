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

ListNode *createListNode(vector<int> nums)
{
    ListNode *head = new ListNode();
    ListNode *temp = head;
    for (int i = 0; i < nums.size(); i++)
    {
        head->val = nums[i];
        if (i != nums.size() - 1)
        {
            head->next = new ListNode();
            head = head->next;
        }
    }
    return temp;
}

void printListNode(ListNode *head)
{
    ListNode *cur = head;
    while (cur)
    {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
    return;
}

int sizeListNode(ListNode *head)
{
    int ans = 0;
    ListNode *cur = head;
    while (cur)
    {
        cur = cur->next;
        ans++;
    }
    return ans;
}

// --------------------Snippet-Ends--------------------------------

vector<vector<int>> dp;

bool check(vector<int> &nums, int &m, vector<int> &psum, int i, int j)
{
    // cout << i << " " << j << endl;
    // cout << psum[j + 1] - psum[i] << endl;
    return (psum[j + 1] - psum[i] >= m) || (j - i) == 0;
}

bool helper(vector<int> &nums, int &m, vector<int> &psum, int i, int j)
{
    // cout << i << " " << j << endl;
    if (j - i == 0)
        return true;
    if (dp[i][j] != -1)
        return dp[i][j];
    for (int k = i; k <= j; k++)
    {
        // cout << i << " " << k << " " << k + 1 << " " << j << endl;
        if (check(nums, m, psum, i, k) && check(nums, m, psum, k + 1, j) && helper(nums, m, psum, i, k) && helper(nums, m, psum, k + 1, j))
        {
            dp[i][j] = 1;
            return true;
        }
    }
    dp[i][j] = 0;
    return false;
}

bool canSplitArray(vector<int> &nums, int m)
{
    int n = nums.size();
    vector<int> psum;
    psum.push_back(0);
    for (int &i : nums)
        psum.push_back(psum.back() + i);
    dp.assign(n, vector<int>(n, -1));
    return helper(nums, m, psum, 0, nums.size() - 1);
}

signed main()
{
    vector<int> nums = {2, 3, 3, 2, 3};
    cout << canSplitArray(nums, 6);
}