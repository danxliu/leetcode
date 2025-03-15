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

string reorganizeString(string s)
{
    map<char, int> freq;
    for (char &c : s)
        freq[c]++;
    priority_queue<pair<int, char>> pq;
    for (auto i : freq)
    {
        if (i.second > (s.size() + 1) / 2)
            return "";
        pq.push({i.second, i.first});
    }
    string ans = "";
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (ans.empty() || cur.second != ans.back())
        {
            ans += cur.second;
            if (cur.first > 1)
            {
                pq.push({cur.first - 1, cur.second});
            }
        }
        else
        {
            auto next = pq.top();
            pq.pop();
            ans += next.second;
            if (next.first > 1)
            {
                pq.push({next.first - 1, next.second});
            }
            pq.push(cur);
        }
    }
    return ans;
}

signed main()
{
    cout << reorganizeString("vvvlo");
}