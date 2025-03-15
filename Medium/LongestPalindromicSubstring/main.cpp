#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
        for (int i=0; i<s.size(); i++)
        {
            dp[i][i] = true;
            if (i!=s.size()-1)
            {
                dp[i][i+1] = (s[i] == s[i+1]);
            }
        }
        for (int i=s.size()-3; i>=0; i--)
        {
            for (int j=i+2; j<s.size(); j++)
            {
                dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
            }
        }
        string smx = "";
        int mx = 0;
        for (int i=0; i < s.size(); i++)
        {
            for (int j=0; j<s.size(); j++)
            {
                if (dp[i][j] && j-i+1 > mx)
                {
                    mx = j-i+1;
                    smx = s.substr(i, j-i+1);
                }
            }
        }
        return smx;
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("cbbd");
}