#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int> &nums)
{
    vector<int> sol;
    sol.push_back(nums[0]); for (int i = 1; i < nums.size(); i++)
    {
        sol.push_back(nums[i] + sol[i - 1]);
    }
    return sol;
}

int main()
{
}