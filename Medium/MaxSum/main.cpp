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

long long maxSum(vector<int> &nums, int m, int k)
{
    map<int, int> mp;
    long long ans = 0;
    long long csum = 0;
    int i = 0;
    while (i < k)
    {
        mp[nums[i]]++;
        csum += nums[i];
        i++;
    }
    if (mp.size() >= m)
        ans = max(csum, ans);

    for (; i < nums.size(); i++)
    {
        int remove = nums[i - k];
        // cout << remove << " " << nums[i] << endl;
        csum -= remove;
        mp[remove]--;
        if (!mp[remove])
        {
            mp.erase(remove);
        }
        csum += nums[i];
        mp[nums[i]]++;
        if (mp.size() >= m)
        {
            ans = max(csum, ans);
        }
    }
    return ans;
}

signed main()
{
    vector<int> nums = {1, 1, 1, 3};
    cout << maxSum(nums, 2, 2);
}