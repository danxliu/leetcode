#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    vector<int> t;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            t.push_back(nums[i]);
        }
    }
    nums = t;
    return t.size();
}

int main()
{
    vector<int> nums = {0, 2, 1, 2, 3, 0, 4, 2};
    cout << removeElement(nums, 2);
}