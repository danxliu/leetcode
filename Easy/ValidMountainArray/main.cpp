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

bool validMountainArray(vector<int> &arr)
{
    bool state = true;
    for (int i = 1; i < arr.size(); i++)
    {
        if (state && arr[i] < arr[i - 1])
        {
            if (i == 1)
                return false;
            state = false;
        }
        else if (!state && arr[i] > arr[i - 1])
            return false;
        else if (arr[i] == arr[i - 1])
            return false;
    }
    return true;
}

signed main()
{
    vector<int> arr = {0, 3, 2, 1};
    cout << validMountainArray(arr);
}