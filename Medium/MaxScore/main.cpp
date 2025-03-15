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

static bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
{
    vector<pair<int, int>> nums;
    for (int i = 0; i < nums1.size(); i++)
    {
        nums.push_back({nums1[i], nums2[i]});
    }
    sort(nums.begin(), nums.end(), compare);
    long long curScore = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        curScore += nums[i].first;
        pq.push(nums[i].first);
    }
    long long ans = curScore * nums[k - 1].second;
    for (int i = k; i < nums.size(); i++)
    {
        curScore -= pq.top();
        curScore += nums[i].first;
        pq.pop();
        pq.push(nums[i].first);
        ans = max(ans, curScore * nums[i].second);
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {4, 2, 3, 1, 1};
    vector<int> nums2 = {7, 5, 10, 9, 6};
    int k = 1;
    cout << maxScore(nums1, nums2, k);
}