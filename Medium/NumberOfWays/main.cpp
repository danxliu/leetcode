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

const int mod = 1000000007;
int nCr(int n, int r)
{
    if (r == 0)
        return 1;
    vector<int> v(r + 1, 0);
    v[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = r; j > 0; j--)
            v[j] = ((v[j] % mod) + (v[j - 1] % mod)) % mod;
    }
    return v[r];
}
int numberOfWays(int startPos, int endPos, int k)
{
    int delta = abs(endPos - startPos);
    if (delta % 2 != k % 2)
        return 0;
    int forward = delta + (k - delta) / 2;
    // answer is k choose forward
    return nCr(k, forward);
}

signed main()
{
    cout << numberOfWays(0, 60, 120);
}