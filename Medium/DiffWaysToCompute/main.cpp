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

vector<int> helper(string expression, map<string, vector<int>> &dp)
{
    if (dp.count(expression))
        return dp[expression];
    vector<int> ans;
    bool check = false;
    for (int i = 0; i < expression.size(); i++)
    {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*')
        {
            check = true;
            string prev = expression.substr(0, i);
            string next = expression.substr(i + 1);
            vector<int> prevV = helper(prev, dp);
            vector<int> nextV = helper(next, dp);
            for (int &j : prevV)
            {
                for (int &k : nextV)
                {
                    if (c == '+')
                        ans.push_back(j + k);
                    else if (c == '*')
                        ans.push_back(j * k);
                    else
                        ans.push_back(j - k);
                }
            }
        }
    }
    if (!check)
    {
        ans.push_back(stoi(expression));
    }
    dp[expression] = ans;
    return ans;
}

vector<int> diffWaysToCompute(string expression)
{
    map<string, vector<int>> dp;
    return helper(expression, dp);
}

signed main()
{
    vector<int> dff = diffWaysToCompute("11");
    for (int &i : dff)
    {
        cout << i << endl;
    }
}