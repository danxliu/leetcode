#include <bits/stdc++.h>
using namespace std;

int deleteAndEarn(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<pair<int, int>> compNums; // compressed nums to number, repeats

    int cur = 1;
    compNums.push_back({0, 0});
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            compNums.push_back({nums[i - 1], cur});
            cur = 0;
        }
        cur++;
    }
    compNums.push_back({nums[nums.size() - 1], cur});
    vector<int> dp(compNums.size() + 3, 0);
    dp[1] = compNums[1].first * compNums[1].second;
    for (int i = 2; i < compNums.size(); i++)
    {
        if (compNums[i].first == compNums[i - 1].first + 1)
            dp[i] = max(dp[i - 2] + compNums[i].first * compNums[i].second, dp[i - 1]);
        else
            dp[i] = dp[i - 1] + compNums[i].first * compNums[i].second;
    }
    return dp[compNums.size() - 1];
}

int main()
{
    vector<int> nums{3, 4, 2};
    cout << deleteAndEarn(nums);
}