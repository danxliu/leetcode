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

int longestArithSeqLength(vector<int> &nums)
{
    unordered_map<int, int> dp[nums.size()];
    int ans = 2;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = nums[i] - nums[j];
            dp[i][diff] = 2;
            if (dp[j].count(diff))
            {
                dp[i][diff] = max(dp[j][diff] + 1, dp[i][diff]);
                ans = max(dp[i][diff], ans);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 6, 9, 12};
    cout << longestArithSeqLength(arr);
}