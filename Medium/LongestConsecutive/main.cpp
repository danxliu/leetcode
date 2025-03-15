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

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> new_nums;
    for (int i = 0; i < nums.size(); i++)
    {
        new_nums.insert(nums[i]);
    }

    int ans = 0;
    for (auto it = new_nums.begin(); it != new_nums.end(); it++)
    {
        int cur = *it;
        int len = 1;

        if (new_nums.find(cur - 1) != new_nums.end())
        {
            continue;
        }

        while (new_nums.find(cur) != new_nums.end())
        {
            cur++;
            len++;
        }
        ans = max(ans, len - 1);
    }
    return ans;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums);
}