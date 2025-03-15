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

int minExtraChar(string s, vector<string> &dictionary)
{
    vector<int> dp(s.size() + 1, 1e9);
    dp[0] = 0;
    // Store dictionary as unordered_set
    unordered_set<string> dict;
    for (string &s : dictionary)
    {
        dict.insert(s);
    }

    for (int i = 1; i <= s.size(); i++)
    {
        dp[i] = dp[i - 1] + 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (dict.count(s.substr(j, i - j)))
            {
                dp[i] = min(dp[i], dp[j]);
            }
        }
    }
    return dp.back();
}

signed main()
{
    string s = "sayhelloworld";
    vector<string> dictionary = {"hello", "world"};
    cout << minExtraChar(s, dictionary);
}