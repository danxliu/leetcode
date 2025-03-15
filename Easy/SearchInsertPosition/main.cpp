#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {

        int mid = (low + high) / 2;
        cout << mid << " " << low << " " << high << endl;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (target < nums[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    cout << searchInsert(nums, 2);
}