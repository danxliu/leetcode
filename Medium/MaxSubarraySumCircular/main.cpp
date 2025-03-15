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

int maxSubarraySumCircular(vector<int> &nums)
{
    int cur_max = 0;
    int cur_min = 0;
    int sum = 0;
    int max_sum = nums[0];
    int min_sum = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        cur_max = max(cur_max + nums[i], nums[i]);
        max_sum = max(max_sum, cur_max);
        cur_min = min(cur_min + nums[i], nums[i]);
        min_sum = min(min_sum, cur_min);
        sum += nums[i];
    }
    if (sum == min_sum)
        return max_sum;
    return max(max_sum, sum - min_sum);
}

int main()
{
}