#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define FASTIO ios::sync_with_stdio(0), cin.tie(0);
// -----------------------------------------------------------

int check(vector<int> &dist, double hour, double speed)
{
    // Check if given speed is valid
    double ans = 0;
    for (int i = 0; i < dist.size() - 1; i++)
    {
        ans += ceil(dist[i] / speed);
    }
    ans += dist.back() / speed;
    return ans <= hour;
}
int minSpeedOnTime(vector<int> &dist, double hour)
{
    // Binary search for train speed
    int high = 1e9;
    int low = 1;
    while (low < high)
    {
        int mid = (high + low) / 2;
        if (check(dist, hour, (double)mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (high == 1e9)
    {
        return -1;
    }
    return low;
}

int main()
{
    FASTIO
    vector<int> dist = {1, 1};
    double hour = 1.0;
    cout << minSpeedOnTime(dist, hour);
}