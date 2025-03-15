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

int findNumberOfLIS(vector<int> &nums)
{
    vector<int> dp;
    vector<int> count;
    dp.assign(nums.size(), 1);
    count.assign(nums.size(), 1);
    int maxLen = 0;
    if (nums.size() == 1)
        return 1;
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                if (dp[i] == dp[j] + 1)
                {
                    count[i] += count[j];
                }
                else if (dp[i] < dp[j] + 1)
                {
                    count[i] = count[j];
                    dp[i] = dp[j] + 1;
                }
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (dp[i] == maxLen)
        {
            ans += count[i];
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << findNumberOfLIS(nums);
}