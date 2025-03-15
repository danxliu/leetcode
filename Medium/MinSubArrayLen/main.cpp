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

int minSubArrayLen(int target, vector<int> &nums)
{
    int len = 0;
    int sum = 0;
    int l = 0;
    int r = 0;
    while (sum < target && r < nums.size())
    {
        len++;
        sum += nums[r];
        r++;
    }
    int mn = 0;
    if (sum >= target)
    {
        mn = len;
    }

    while (r < nums.size() || sum >= target)
    {
        sum -= nums[l];
        l++;
        len--;
        while (sum < target && r < nums.size())
        {
            len++;
            sum += nums[r];
            r++;
        }
        if (sum >= target)
        {
            mn = min(mn, len);
        }
    }
    return mn;
}

int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(7, nums);
}