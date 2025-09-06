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

int countSubstrings(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i=0; i<n; i++) {
        dp[i][i] = true;
    }
    for (int i=1; i<n; i++) {
        dp[i-1][i] = (s[i-1] == s[i]);
    }

    for (int len = 2; len<n; len++) {
        for (int l = 0; l<n; l++) {
            int r = l + len;
            if (r >= n) continue;

            dp[l][r] = dp[l+1][r-1] && (s[l] == s[r]);
        }
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans += dp[i][j];
        }
    }
    return ans;
}

signed main()
{
    cout << countSubstrings("aaa") << endl;
}