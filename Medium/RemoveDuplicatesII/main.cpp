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

int removeDuplicates(vector<int> &nums)
{
    int val = nums[0] - 1;
    int num = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (val != nums[i])
        {
            val = nums[i];
            num = 1;
        }
        else
        {
            num++;
        }
        if (num == 3)
        {
            num--;
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    return nums.size();
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}