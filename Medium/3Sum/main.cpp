#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    ans.clear();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int j = i + 1;
        int k = nums.size() - 1;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                while (j < k && nums[j] == nums[j + 1])
                    j++;
                while (j < k && nums[k] == nums[k - 1])
                    k--;
                j++;
                k--;
            }
            else if (sum < 0)
            {
                // j needs to move up
                j++;
            }
            else if (sum > 0)
            {
                // k needs to move down
                k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1};
    vector<vector<int>> ans = threeSum(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}