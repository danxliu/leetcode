#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < m || j < n)
    {
        if (i >= m)
        {
            ans.push_back(nums2[j]);
            j++;
            continue;
        }
        if (j >= n)
        {
            ans.push_back(nums1[i]);
            i++;
            continue;
        }
        if (i < m && j < n)
        {
            if (nums1[i] > nums2[j])
            {
                ans.push_back(nums2[j]);
                j++;
            }
            else
            {
                ans.push_back(nums1[i]);
                i++;
            }
        }
    }
    nums1.clear();
    for (int i = 0; i < ans.size(); i++)
    {
        nums1.push_back(ans[i]);
    }
}

int main()
{
    vector<int> num1 = {1, 2, 3, 0, 0, 0};
    vector<int> num2 = {2, 5, 6};
    merge(num1, 3, num2, 3);
}