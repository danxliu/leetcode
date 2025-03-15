#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define FASTIO ios::sync_with_stdio(0), cin.tie(0);
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

// --------------------Snippet-Ends--------------------------------
uint32_t reverseBits(uint32_t n)
{
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++)
    {
        // get value of ith bit
        ans = (ans << 1) + (n >> i & 1);
    }
    return ans;
}

int main()
{
    cout << reverseBits(43261596);
}