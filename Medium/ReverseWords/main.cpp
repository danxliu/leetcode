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
string reverseWords(string s)
{
    vector<string> words;
    string cur = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ' && cur.size() > 0)
        {
            words.push_back(cur);
            cur = "";
        }
        else if (s[i] != ' ')
        {
            cur += s[i];
        }
    }
    if (cur.size() > 0)
    {
        words.push_back(cur);
    }
    reverse(words.begin(), words.end());
    string ans = "";
    for (int i = 0; i < words.size(); i++)
    {
        ans += words[i] + " ";
    }
    return ans.substr(0, ans.size() - 1);
}

int main()
{
    cout << reverseWords("a good   example");
}