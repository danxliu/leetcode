#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    int cursum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (2 * cursum + nums[i] == sum)
            return i;
        cursum += nums[i];
    }
    return -1;
}

int main()
{
    vector<int> arr{2, 1, -1};
    int ans = pivotIndex(arr);
    cout << ans << endl;
}