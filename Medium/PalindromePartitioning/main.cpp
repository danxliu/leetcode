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

void dfs(vector<vector<string>> &ans, vector<vector<bool>> &dp, vector<string> &cur, string &s, int i)
{
    if (i == s.size())
    {
        ans.push_back(cur);
        return;
    }
    for (int j = i; j < s.size(); j++)
    {
        if (s[j] == s[i] && (i + 1 > j - 1 || dp[i + 1][j - 1]))
        {
            dp[i][j] = true;
            cur.push_back(s.substr(i, j - i + 1));
            dfs(ans, dp, cur, s, j + 1);
            cur.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    for (int i = 0; i < s.size(); i++)
    {
        dp[i][i] = true;
    }
    vector<vector<string>> ans;
    vector<string> cur;
    dfs(ans, dp, cur, s, 0);
    return ans;
}

signed main()
{
    vector<vector<string>> ans = partition("a");
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}