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

int modPower(int i)
{
    int res = 1;
    int x = 2;
    while (i > 0)
    {
        if (i % 2 == 1)
        {
            res *= x;
        }
        i = i >> 1;
        x = (1 << x) % int(1e9 + 7);
    }
    return res % int(1e9 + 7);
}

int numSubseq(vector<int> &nums, int target)
{
    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        // let i be the smallest number
        // binary search for number leq to target - nums[i]
        auto lit = upper_bound(nums.begin(), nums.end(), target - nums[i]);
        if (lit == nums.begin())
            continue; // all numbers are greater than target - nums[i]
        lit--;
        int j = lit - nums.begin();
        if (j < i)
            continue;
        if (j == i)
        {
            ans += ((nums[i] * 2) <= target);
            continue;
        }
        ans += modPower(j - i);
        ans %= int(1e9 + 7);
    }
    return ans;
}

signed main()
{
    vector<int> nums = {2, 3, 3, 4, 6, 7};
    cout << numSubseq(nums, 12);
}