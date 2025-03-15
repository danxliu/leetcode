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

int maxArea(vector<int> &height)
{
    int l = 0;
    int r = height.size() - 1;
    int mx = (r - l) * min(height[l], height[r]);
    while (l < r)
    {
        if (height[l] > height[r])
        {
            r--;
        }
        else
        {
            l++;
        }
        mx = max(mx, (r - l) * min(height[l], height[r]));
    }
    return mx;
}

int main()
{
    vector<int> height = {1,
                          8,
                          6,
                          2,
                          5,
                          4,
                          8,
                          3,
                          7};
    cout << maxArea(height);
}