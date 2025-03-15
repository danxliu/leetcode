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

bool isSame(vector<int> &a, vector<int> &b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> ans;
    vector<vector<int>> chars;
    vector<bool> visited;
    visited.assign(strs.size(), false);
    chars.assign(strs.size(), vector<int>());
    for (int i = 0; i < strs.size(); i++)
    {
        chars[i].assign(26, 0);
        for (int j = 0; j < strs[i].size(); j++)
        {
            chars[i][strs[i][j] - 'a']++;
        }
    }

    for (int i = 0; i < strs.size(); i++)
    {
        if (visited[i])
        {
            continue;
        }
        ans.push_back({strs[i]});
        visited[i] = true;
        for (int j = i + 1; j < strs.size(); j++)
        {
            if (!visited[j] && isSame(chars[i], chars[j]))
            {
                ans.back().push_back(strs[j]);
                visited[j] = true;
            }
        }
    }
    return ans;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}