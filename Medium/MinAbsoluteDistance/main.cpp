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

int minAbsoluteDifference(vector<int> &nums, int x)
{
    multiset<int> window;
    for (int i = x; i < nums.size(); i++)
    {
        window.insert(nums[i]);
    }
    int mn = 1e9;
    for (int i = 0; i < nums.size() - x; i++)
    {
        // get two closest values to nums[i] in the window
        auto r = window.lower_bound(nums[i]);
        auto l = window.lower_bound(nums[i]);
        if (l != window.begin())
        {
            l--;
            mn = min(mn, abs(nums[i] - *l));
        }
        if (r != window.end())
        {
            mn = min(mn, abs(nums[i] - *r));
        }
        window.erase(window.find(nums[i + x]));
    }
    return mn;
}

signed main()
{
    vector<int> nums = {4,
                        3,
                        2,
                        4};
    cout << minAbsoluteDifference(nums, 2);
}