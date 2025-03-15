#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 1;
        int mx = nums[0];
        int curmx = nums[0];
        if (nums.size()-1 == 0) return 0;
        for (int i=0; i<nums.size(); i++)
        {
            curmx = max(curmx, i+nums[i]);
            if (i == nums.size()-1) return steps;
            if (i == mx)
            {
                mx = curmx;
                steps++;
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {};
    cout << s.jump(nums) << endl;
}