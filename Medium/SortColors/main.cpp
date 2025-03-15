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
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void sortColors(vector<int> &nums)
{
    int cols[3] = {0, 0, 0};
    for (int &i : nums)
        cols[i]++;
    int start[3] = {0, 0, 0};
    start[1] = cols[0];
    start[2] = start[1] + cols[1];

    for (int i = 0; i < 3; i++)
    {
        // sort the ith color
        cout << start[i] << " " << start[i] + cols[i] << endl;
        for (int l = start[i]; l < start[i] + cols[i]; l++)
        {
            if (nums[l] == i)
                continue;
            int r = l + 1;
            while (nums[r] != i)
                r++;
            swap(nums[l], nums[r]);
        }
    }
}

signed main()
{
    vector<int> nums = {0, 2, 1};
    sortColors(nums);
    for (int &i : nums)
        cout << i << " ";
    cout << endl;
}