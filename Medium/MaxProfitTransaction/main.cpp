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

int maxProfit(vector<int> &prices, int fee)
{
    vector<int> buy;
    vector<int> sell;
    buy.assign(prices.size() + 1, 0);
    sell.assign(prices.size() + 1, 0);
    buy[1] = -prices[0];
    for (int i = 2; i <= prices.size(); i++)
    {
        int price = prices[i - 1];
        buy[i] = max(sell[i - 1] - price, buy[i - 1]);
        sell[i] = max(sell[i - 1], buy[i - 1] + price - fee);
    }
    return sell[prices.size()];
}

int main()
{
    vi prices{1, 3, 7, 5, 10, 3};
    cout << maxProfit(prices, 3);
}