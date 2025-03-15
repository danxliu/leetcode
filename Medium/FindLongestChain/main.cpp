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

bool compare(vector<int> p1, vector<int> p2)
{
    return p1[1] < p2[1];
}

int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end());
    int num = 0;
    int cur = INT_MIN;
    for (int i = 0; i < pairs.size(); i++)
    {
        if (pairs[i][0] > cur)
        {
            cur = pairs[i][1];
            num++;
        }
    }
    return num;
}

int main()
{
    vector<vector<int>> pairs = {{-10, -8}, {8, 9}, {-5, 0}, {6, 10}, {-6, -4}, {1, 7}, {9, 10}, {-4, 7}};
    cout << findLongestChain(pairs);
}