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

vector<vector<int>> twoSum(vector<int> &numbers, long long target, int start)
{
    vector<vector<int>> ans;
    int low = start;
    int high = numbers.size() - 1;
    while (low < high)
    {
        if (numbers[low] + numbers[high] > target || (high < numbers.size() - 1 && numbers[high] == numbers[high + 1]))
        {
            high--;
        }
        else if (numbers[low] + numbers[high] < target || (low > start && numbers[low] == numbers[low - 1]))
        {
            low++;
        }
        else
        {
            ans.push_back({numbers[low++], numbers[high--]});
        }
    }
    return ans;
}

vector<vector<int>> recurse(int start, int k, long long target, vector<int> &nums)
{
    vector<vector<int>> ans;
    if (start == nums.size())
    {
        return ans;
    }

    if (nums[start] > target / k || nums[nums.size() - 1] < target / k)
    {
        return ans;
    }

    if (k == 2)
    {
        return twoSum(nums, target, start);
    }

    for (int i = start; i < nums.size(); ++i)
    {
        if (i == start || nums[i - 1] != nums[i])
        {
            for (vector<int> &subset : recurse(i + 1, k - 1, static_cast<long long>(target) - nums[i], nums))
            {
                ans.push_back({nums[i]});
                ans.back().insert(end(ans.back()), begin(subset), end(subset));
            }
        }
    }
    return ans;
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    return recurse(0, 4, target, nums);
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ans = fourSum(nums, target);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}