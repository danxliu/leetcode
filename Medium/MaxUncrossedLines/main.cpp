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

int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
{
    int dp[nums1.size() + 1][nums2.size() + 1];
    for (int i = 0; i <= nums1.size(); i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= nums2.size(); i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= nums1.size(); i++)
    {
        for (int j = 1; j <= nums2.size(); j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[nums1.size()][nums2.size()];
}

int main()
{
    vector<int> nums1 = {2, 5, 1, 2, 5};
    vector<int> nums2 = {10, 5, 2, 1, 5, 2};
    cout << maxUncrossedLines(nums1, nums2);
}
