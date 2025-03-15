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

// int mincostTickets(vector<int> &days, vector<int> &costs)
// {
//     int dp[days.size() + 1];
//     for (int i = 0; i <= days.size(); i++)
//     {
//         dp[i] = INT_MAX;
//     }
//     dp[0] = 0;
//     for (int i = 1; i <= days.size(); i++)
//     {
//         dp[i] = min(dp[i], dp[i - 1] + costs[0]);
//         dp[i] = min(dp[i], dp[i - 1] + costs[1]);
//         dp[i] = min(dp[i], dp[i - 1] + costs[2]);
//         for (int j = i + 1; j <= days.size(); j++)
//         {
//             if (days[i - 1] + 7 > days[j - 1])
//             {
//                 dp[j] = min(dp[j], dp[i - 1] + costs[1]);
//             }
//             if (days[i - 1] + 30 > days[j - 1])
//             {
//                 dp[j] = min(dp[j], dp[i - 1] + costs[2]);
//             }
//             else
//                 break;
//         }
//     }
//     return dp[days.size()];
// }

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    // faster solution, linear time in relation to the largest day
    vector<int> dp(days.back() + 1, 0);
    set<int> d;
    for (const int &i : days)
    {
        d.insert(i);
    }
    for (int i = 1; i <= dp.size(); i++)
    {
        if (d.find(i) != d.end())
        {
            dp[i] = min(min(dp[max(i - 1, 0)] + costs[0], dp[max(i - 7, 0)] + costs[1]), dp[max(i - 30, 0)] + costs[2]);
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    return dp.back();
}

int main()
{
    vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> costs = {2, 7, 15};
    cout << mincostTickets(days, costs);
}