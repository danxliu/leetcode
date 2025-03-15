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

int findMaxForm(vector<string> &strs, int m, int n)
{
    int dp[m + 1][n + 1];
    vector<pair<int, int>> strnum; // 0s and 1s
    for (string &s : strs)
    {
        int o = 0;
        int z = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                o++;
            }
            else
            {
                z++;
            }
        }
        strnum.push_back({z, o});
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (pair<int, int> num : strnum)
    {
        for (int i = m; i >= 0; i--)
        {
            for (int j = n; j >= 0; j--)
            {
                if (i >= num.first && j >= num.second)
                {
                    dp[i][j] = max(dp[i][j], dp[i - num.first][j - num.second] + 1);
                }
            }
        }
    }
    return dp[m][n];
}

int main()
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5;
    int n = 3;
    cout << findMaxForm(strs, m, n);
}