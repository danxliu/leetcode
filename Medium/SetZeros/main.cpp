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

void setZeroes(vector<vector<int>> &matrix)
{
    bool col1 = false;
    bool row1 = false;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][0] == 0)
        {
            col1 = true;
        }
    }
    for (int i = 0; i < matrix[0].size(); i++)
    {
        if (matrix[0][i] == 0)
        {
            row1 = true;
        }
    }
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (!matrix[i][0] || !matrix[j][0])
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (col1)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i][0] = 0;
        }
    }
    if (row1)
    {
        for (int i = 0; i < matrix[0].size(); i++)
        {
            matrix[0][i] = 0;
        }
    }
}

int main()
{
}