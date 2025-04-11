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
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";
    return;
}

// --------------------Snippet-Ends--------------------------------

char find(map<char, char> &mp, char a)
{
    if (mp[a] == a)
    {
        return a;
    }
    return find(mp, mp[a]);
}

void unite(map<char, char> &mp, char a, char b)
{
    char pa = find(mp, a);
    char pb = find(mp, b);

    // i cant be bothered to implement size
    mp[pa] = pb;
}

bool equationsPossible(vector<string> &equations)
{
    map<char, char> mp;
    for (string &s : equations)
    {
        if (!mp.count(s[0]))
            mp[s[0]] = s[0];
        if (!mp.count(s[3]))
            mp[s[3]] = s[3];
    }

    for (string &s : equations)
    {
        if (s[1] == '=')
            unite(mp, s[0], s[3]);
    }

    for (string &s : equations)
    {
        if (s[1] == '!')
            if (find(mp, s[0]) == find(mp, s[3]))
                return false;
    }
    return true;
}

signed main()
{
}