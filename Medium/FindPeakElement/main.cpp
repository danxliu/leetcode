#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define FASTIO ios::sync_with_stdio(0), cin.tie(0);
// --------------------Leetcode-Data-Structures--------------------

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// --------------------Snippet-Ends--------------------------------

int helper(vector<int> &nums, int ind)
{
    // Peak
    if ((ind == 0 || nums[ind] > nums[ind - 1]) && (ind == nums.size() - 1 || nums[ind] > nums[ind + 1]))
    {
        return 0;
    }
    // Upward sloping
    else if ((ind != nums.size() - 1 && nums[ind + 1] > nums[ind]) && (ind == 0 || nums[ind] > nums[ind - 1]))
    {
        return 1;
    }
    // Downward sloping
    else if ((ind == nums.size() - 1 || nums[ind + 1] < nums[ind]) && (ind != 0 && nums[ind] < nums[ind - 1]))
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

int findPeakElement(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;
    for (auto &i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int res = helper(nums, mid);
        // cout << mid << " " << res << "\n";
        if (res == 0)
        {
            return mid;
        }
        else if (res == 1)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return 0;
}

int main()
{
    vector<int> nums = {-2147483648, -2147483647};
    cout << findPeakElement(nums);
}
