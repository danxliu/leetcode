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

int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
{
    vector<int> psum(nums.size() + 1, 0);
    for (vector<int> &i : requests)
    {
        psum[i[0]]++;
        psum[i[1] + 1]--;
    }
    int cur = 0;
    multiset<long long> ms;
    for (int i = 0; i < nums.size(); i++)
    {
        cur += psum[i];
        ms.insert(cur);
    }
    sort(nums.begin(), nums.end());
    long long ans = 0;
    int j = 0;
    for (long long i : ms)
    {
        ans += i * nums[j];
        ans %= int(1e9 + 7);
        j++;
    }
    return ans;
}

signed main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 10};
    vector<vector<int>> requests = {{0, 2}, {1, 3}, {1, 1}};
    cout << maxSumRangeQuery(nums, requests);
}