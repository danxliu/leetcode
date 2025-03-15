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

int getMaxLen(vector<int> &nums)
{
    vector<int> dp[2];
    dp[0].assign(nums.size(), 0);
    dp[1].assign(nums.size(), 0);
    if (nums[0] > 0)
        dp[0][0] = 1;
    if (nums[0] < 0)
        dp[1][0] = 1;
    int mx = dp[0][0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            dp[1][i] = dp[0][i - 1] + 1;
            if (dp[1][i - 1] > 0)
                dp[0][i] = max(dp[0][i], dp[1][i - 1] + 1);
        }
        if (nums[i] > 0)
        {
            dp[0][i] = dp[0][i - 1] + 1;
            if (dp[1][i - 1] > 0)
                dp[1][i] = max(dp[1][i], dp[1][i - 1] + 1);
        }
        mx = max(dp[0][i], mx);
    }
    return mx;
}

int main()
{
    vector<int> nums{-16, 0, -5, 2, 2, -13, 11, 8};
    cout << getMaxLen(nums) << endl;
}