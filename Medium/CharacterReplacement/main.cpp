#include <bits/stdc++.h>
using namespace std;
int characterReplacement(string s, int k)
{
    vector<int> curLetters(27, 0);
    int curLargest = -1;
    int mx = 0;
    int st = 0;
    for (int ed = 0; ed < s.size(); ed++)
    {
        curLetters[s[ed] - 'A']++;
        curLargest = *max_element(curLetters.begin(), curLetters.end());
        cout << st << " " << ed << endl;
        if (ed - st + 1 > curLargest + k)
        {
            curLetters[s[st] - 'A']--;
            st++;
        }
        mx = max(mx, ed + 1 - st);
    }
    return mx;
}

int main()
{
    cout << characterReplacement("ABAA", 0) << endl;
}