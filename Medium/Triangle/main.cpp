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

int minimumTotal(vector<vector<int>> &triangle)
{
    // idea: from position i, j, take the minimum of position i-1, j-1 and i-1, j.
    vector<vector<int>> dp;
    dp.assign(triangle.size(), vector<int>());
    int ans = INT_MAX;
    dp[0].push_back(triangle[0][0]);
    if (triangle.size() == 1)
    {
        return dp[0][0];
    }
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            int nval = INT_MAX;
            if (j < triangle[i - 1].size())
            {
                nval = min(nval, dp[i - 1][j]);
            }
            if (j - 1 >= 0)
            {
                nval = min(nval, dp[i - 1][j - 1]);
            }
            nval += triangle[i][j];
            if (i == triangle.size() - 1)
            {
                ans = min(ans, nval);
            }
            dp[i].push_back(nval);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(triangle);
}