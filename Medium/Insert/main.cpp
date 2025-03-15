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

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    bool inserted = false;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (newInterval[0] < intervals[i][0])
        {
            intervals.insert(intervals.begin() + i, newInterval);
            inserted = true;
            break;
        }
    }
    if (!inserted)
    {
        intervals.push_back(newInterval);
    }
    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size(); i++)
    {
        vector<int> cur = intervals[i];
        while (i < intervals.size() && min(cur[1], intervals[i][1]) - max(cur[0], intervals[i][0]) >= 0)
        {
            cur = vector<int>{min(cur[0], intervals[i][0]), max(cur[1], intervals[i][1])};
            i++;
        }
        i--;
        ans.push_back(cur);
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals{{1, 3}, {6, 9}};
    vector<int> newInterval{2, 7};
    vector<vector<int>> ans = insert(intervals, newInterval);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}