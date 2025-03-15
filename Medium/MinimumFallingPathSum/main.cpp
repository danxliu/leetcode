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

int minFallingPathSum(vector<vector<int>> &matrix)
{
    vector<vector<int>> dp;
    dp.assign(matrix.size(), vector<int>());
    for (int i = 0; i < matrix[0].size(); i++)
    {
        dp[0].push_back(matrix[0][i]);
    }
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            int nval = dp[i - 1][j];
            if (j - 1 >= 0)
            {
                nval = min(dp[i - 1][j - 1], nval);
            }
            if (j + 1 < matrix[i - 1].size())
            {
                nval = min(dp[i - 1][j + 1], nval);
            }
            nval += matrix[i][j];
            dp[i].push_back(nval);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < matrix[matrix.size() - 1].size(); i++)
    {
        ans = min(ans, dp[matrix.size() - 1][i]);
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{-19, 57}, {-40, -5}};
    cout << minFallingPathSum(matrix);
}