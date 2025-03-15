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

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int ttank = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        ttank += gas[i];
        ttank -= cost[i];
    }
    if (ttank < 0)
        return -1;
    int ctank = 0;
    int mind = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        ctank = ctank + gas[i] - cost[i];
        if (ctank < 0)
        {
            ctank = 0;
            mind = i + 1;
        }
    }

    return mind;
}

int main()
{
    vi gas{3, 1, 1};
    vi cost{1, 2, 2};
    cout << canCompleteCircuit(gas, cost);
}