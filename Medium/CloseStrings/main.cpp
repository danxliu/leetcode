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

bool closeStrings(string word1, string word2)
{
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());
    if (word1 == word2)
        return true;
    if (word1.size() != word2.size())
        return false;
    set<char> count1;
    set<char> count2;
    for (char &c : word1)
        count1.insert(c);
    for (char &c : word2)
        count2.insert(c);
    if (count1 != count2)
        return false;
    unordered_multiset<int> char1;
    unordered_multiset<int> char2;
    int c1 = 1;
    int c2 = 1;
    for (int i = 1; i < word1.size(); i++)
    {
        if (word1[i] == word1[i - 1])
            c1++;
        else
        {
            char1.insert(c1);
            c1 = 1;
        }
        if (word2[i] == word2[i - 1])
            c2++;
        else
        {
            char2.insert(c2);
            c2 = 1;
        }
    }
    char1.insert(c1);
    char2.insert(c2);
    for (auto it1 = char1.begin(); it1 != char1.end(); it1++)
    {
        auto it2 = char2.find(*it1);
        if (it2 == char2.end())
            return false;
        char2.erase(it2);
    }
    return true;
}

signed main()
{
    cout << closeStrings("abbzzca", "babzzcz");
}