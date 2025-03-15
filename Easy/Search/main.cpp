#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo <= hi)
    {
        int md = (lo + hi) / 2;
        if (nums[md] == target)
        {
            return md;
        }
        else if (nums[md] > target)
        {
            hi = md - 1;
        }
        else
        {
            lo = md + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums{2, 5};
    int target = 0;
    cout << search(nums, target);
}