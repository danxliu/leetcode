#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    int slen = s.length();
    int plen = p.length();
    vector<int> ans;
    if (plen > slen)
        return ans;
    vector<int> pf;
    vector<int> cf;
    pf.assign(27, 0);
    cf.assign(27, 0);
    for (int i = 0; i < plen; i++)
    {
        cout << s[i] << endl;
        pf[p[i] - 'a']++;
        cf[s[i] - 'a']++;
    }
    cout << "beginning ";
    for (int i = 0; i < pf.size(); i++)
    {
        cout << pf[i] << " ";
    }
    cout << endl;
    if (pf == cf)
        ans.push_back(0);
    for (int j = plen; j < slen; j++)
    {
        cout << "removing " << s[j - plen] << endl;
        cf[s[j - plen] - 'a']--;
        cout << "adding " << s[j] << endl;
        cf[s[j] - 'a']++;
        cout << "cur: ";
        for (int i = 0; i < pf.size(); i++)
        {
            cout << pf[i] << " ";
        }
        cout << endl;
        if (pf == cf)
            ans.push_back(j - plen + 1);
    }
    return ans;
}

int main()
{
    vector<int> ans = findAnagrams("baa", "aa");
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}