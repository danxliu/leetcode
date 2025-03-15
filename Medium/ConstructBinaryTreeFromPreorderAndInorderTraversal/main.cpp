#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
const int INF = 1e9;
const ll LLINF = 4 * 1e18;
const ll MOD = 1e9 + 7;
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef vector<iii> viii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
typedef set<ll> sl;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> lll;
typedef vector<pll> vll;
typedef vector<lll> vlll;
typedef priority_queue<ll> pql;
typedef stack<ll> stl;
typedef queue<ll> ql;
typedef deque<ll> dl;
typedef map<ll, ll> mll;
#define f first
#define s second
// -----------------------------------------------------------
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int ind = 0;
    return helper(preorder, inorder, ind, 0, 0);
}

TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int &ind, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int root = start;
    while (inorder[root] != preorder[ind])
    {
        root++;
    }
    ind++;
    TreeNode *newRoot = new TreeNode(preorder[ind]);
    newRoot->left = helper(preorder, inorder, ind, start, root - 1);
    newRoot->right = helper(preorder, inorder, ind, root + 1, end);
    return newRoot;
}

int main()
{
}