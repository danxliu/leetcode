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

bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
{
    map<int, vector<int>> mp;
    for (vector<int> &piece : pieces)
    {
        mp[piece[0]] = piece;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        auto cur = mp.find(arr[i]);
        if (cur == mp.end())
            return false;
        for (int &j : cur->second)
        {
            if (arr[i] != j)
                return false;
            i++;
        }
        i--;
    }
    return true;
}

signed main()
{
    vector<int> arr = {91, 4, 64, 78};
    vector<vector<int>> pieces = {{78}, {4, 64}, {91}};
    cout << canFormArray(arr, pieces);
}