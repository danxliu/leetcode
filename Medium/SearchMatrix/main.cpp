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

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // Find the y index, then find the x index
    int l = 0;
    int r = matrix.size();
    while (l < r)
    {
        int m = (l + r) / 2;
        if (matrix[m][0] <= target)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    if (l == 0)
        return false;
    int row = l - 1;
    l = 0;
    r = matrix[row].size() - 1;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (matrix[row][m] == target)
            return true;
        else if (matrix[row][m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return matrix[row][l] == target;
}

signed main()
{
    vector<vector<int>> matrix = {{1}};
    cout << searchMatrix(matrix, 1);
}