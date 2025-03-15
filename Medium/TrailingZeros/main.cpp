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

int trailingZeroes(int n)
{
    int fives = 0;
    int twos = 0;
    for (int i = 1; i <= n; i++)
    {
        int cur = i;
        while (cur % 2 == 0)
        {
            twos++;
            cur /= 2;
        }
        while (cur % 5 == 0)
        {
            fives++;
            cur /= 5;
        }
    }
    return min(fives, twos);
}

int main()
{
    cout << trailingZeroes(1);
}