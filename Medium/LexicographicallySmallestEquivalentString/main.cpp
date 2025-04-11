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

    // Make lexicographically smallest the new parent
    if (pa < pb) {
        mp[pb] = pa;
    } else {
        mp[pa] = pb;
    }
}

string smallestEquivalentString(string s1, string s2, string baseStr) {
    map<char, char> mp;
    int n = s1.size();
    for (int i=0; i<n; i++) {
        if (!mp.count[s1[i]]) mp[s1[i]] = s1[i];
        if (!mp.count[s2[i]]) mp[s2[i]] = s2[i];

        unite(mp, s1[i], s2[i]);
    }

    for (int i=0; i<baseStr.size(); i++) {
        if (!mp.count(baseStr[i])) continue;
        baseStr[i] = find(mp, baseStr[i]);
    }
    return baseStr;
}

signed main() {

}