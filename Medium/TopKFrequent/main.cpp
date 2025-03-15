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

vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> val;
    for (int i = 0; i < nums.size(); i++)
    {
        val[nums[i]]++;
    }
    priority_queue<pair<int, int>> q;
    for (auto it = val.begin(); it != val.end(); it++)
    {
        q.push({it->second * -1, it->first});
        if (q.size() > k)
        {
            q.pop();
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.top().second);
        q.pop();
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> ans = topKFrequent(nums, 2);
    for (int &i : ans)
    {
        cout << i << endl;
    }
}