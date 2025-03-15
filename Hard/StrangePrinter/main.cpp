#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define INF 1e9
#define MOD 1e9 + 7
// #define int ll
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

// --------------------Snippet-Ends--------------------------------

int strangePrinter(string s)
{
    int n = s.size();
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = n + 1;
        }
    }

    for (int length = 1; length <= n; length++)
    {
        for (int left = 0; left <= n - length; left++)
        {
            int right = left + length - 1;
            int j = -1;
            for (int i = left; i < right; i++)
            {
                if (s[i] != s[right] && j == -1)
                {
                    j = i;
                }
                if (j != -1)
                {
                    dp[left][right] = min(dp[left][right], 1 + dp[j][i] + dp[i + 1][right]);
                }
            }
            if (j == -1)
            {
                dp[left][right] = 0;
            }
        }
    }
    return dp[0][n - 1] + 1;
}

signed main()
{
    FASTIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    cout << strangePrinter(s);
    return 0;
}