#include <iostream>
#include <vector>
using namespace std;

// Scenarios
//  n = 3, m = 3
//  sum = 6 -> get avg of 3rd and 4th num
//  1, 2, 3
//  1, 2, 3

// n = 2, m = 3
// sum = 5 -> get 3rd number
// 1, 2
// 1, 2, 3

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    if (nums1.empty())
    {
        if (m % 2 == 0)
            return double(nums2[m / 2] + nums2[m / 2 + 1]) / 2;
        return (nums2[m / 2]);
    }

    if (nums2.empty())
    {
        if (n % 2 == 0)
            return double(nums1[n / 2] + nums1[n / 2 + 1]) / 2;
        return (nums1[n / 2]);
    }
    int sum = n + m;
    int i = 0;
    int j = 0;
    while (true)
    {
        if (i + j + 1 == sum / 2)
        {
            if (sum % 2 == 0)
            {
                return double(nums1[i] + nums2[j]) / 2;
            }
            else
            {
                return max(nums1[i], nums2[j]);
            }
        }
        if (nums1[i] > nums2[j] || i == nums2.size() - 1)
            j++;
        else
            i++;
    }
}

int main()
{
    vector<int> nums1{};
    vector<int> nums2{2, 3};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
}