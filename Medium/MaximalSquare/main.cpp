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

int maximalSquare(vector<vector<char>> &matrix)
{
    vector<vector<int>> dp;
    dp.assign(matrix.size(), vector<int>());
    int ans = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        dp[i].push_back(matrix[i][0] - '0');
        ans = max(ans, dp[i][0]);
    }
    for (int i = 1; i < matrix[0].size(); i++)
    {
        dp[0].push_back(matrix[0][i] - '0');
        ans = max(ans, dp[0][i]);
    }
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == '1')
            {
                dp[i].push_back(min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1);
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i].push_back(0);
            }
        }
    }
    return pow(ans, 2);
}

int main()
{
    // vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    vector<vector<char>> matrix = {{'0', '1'}};
    // vector<vector<char>> matrix = {{'0', '1'}, {'1', '0'}};
    cout << maximalSquare(matrix);
}