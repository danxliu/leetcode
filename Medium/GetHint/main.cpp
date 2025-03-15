#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
using lli = long long int;
using ulli = unsigned long long int;
using ld = long double;
const int INF = 1e9;
const lli LLINF = 4 * 1e18;
const lli MOD = 1e9 + 7;
const ld PI = 3.141592653589793;
// -----------------------------------------------------------

string getHint(string secret, string guess)
{
    map<char, int> mp;
    int bulls = 0;
    int cows = 0;
    for (int i = 0; i < secret.size(); i++)
    {
        mp[secret[i]]++;
    }
    for (int i = 0; i < guess.size(); i++)
    {
        if (guess[i] == secret[i])
        {
            bulls++;
            mp[secret[i]]--;
        }
    }
    for (int i = 0; i < guess.size(); i++)
    {
        if (mp[guess[i]] > 0 && guess[i] != secret[i])
        {
            cows++;
            mp[guess[i]]--;
        }
    }
    string ans = "";
    ans += to_string(bulls);
    ans += 'A';
    ans += to_string(cows);
    ans += 'B';
    return ans;
}

int main()
{
    cout << getHint("00112233445566778899", "16872590340158679432");
}