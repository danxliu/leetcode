#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    return nums.size();
}

int main()
{
    vector<int> nums;
    nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(nums);
}