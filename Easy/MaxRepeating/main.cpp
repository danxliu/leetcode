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

// --------------------Snippet-Ends--------------------------------

int maxRepeating(string sequence, string word)
{
    int ans = 0;
    for (int i = 0; i < sequence.size(); i++)
    {
        int cur = 0;
        int j = i;
        while (j + word.size() <= sequence.size() && sequence.substr(j, word.size()) == word)
        {
            cur++;
            j += word.size();
        }
        ans = max(cur, ans);
    }
    return ans;
}

signed main()
{
    cout << maxRepeating("a", "a");
}