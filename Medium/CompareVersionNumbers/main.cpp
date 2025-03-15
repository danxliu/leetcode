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

int helper(string &v1, string &v2)
{
    if (!v1.size() && !v2.size())
        return 0;
    string c1 = "";
    string c2 = "";
    int i;
    for (i = 0; i < v1.size() && v1[i] != '.'; i++)
    {
        if (v1[i] == '0' && c1.size() == 0)
            continue;
        c1 += v1[i];
    }
    v1 = (i + 1 < v1.size()) ? v1.substr(i + 1) : "";
    for (i = 0; i < v2.size() && v2[i] != '.'; i++)
    {
        if (v2[i] == '0' && c2.size() == 0)
            continue;
        c2 += v2[i];
    }
    v2 = (i + 1 < v2.size()) ? v2.substr(i + 1) : "";
    int i1 = c1 == "" ? 0 : stoi(c1);
    int i2 = c2 == "" ? 0 : stoi(c2);
    if (i1 < i2)
        return -1;
    if (i1 > i2)
        return 1;

    return helper(v1, v2);
}

int compareVersion(string version1, string version2)
{
    return helper(version1, version2);
}

signed main()
{
    cout << compareVersion("0.1", "1.1");
}