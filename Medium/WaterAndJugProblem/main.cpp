#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
{
    int totCap = jug1Capacity + jug2Capacity;
    queue<int> q;
    set<int> visited;
    q.push(0);
    visited.insert(0);
    while (!q.empty())
    {
        int curCap = q.front();
        if (curCap == targetCapacity)
            return true;
        q.pop();
        if (curCap + jug1Capacity <= totCap && visited.find(curCap + jug1Capacity) == visited.end())
        {
            q.push(curCap + jug1Capacity);
            visited.insert(curCap + jug1Capacity);
        }
        if (curCap - jug1Capacity >= 0 && visited.find(curCap - jug1Capacity) == visited.end())
        {
            q.push(curCap - jug1Capacity);
            visited.insert(curCap - jug1Capacity);
        }
        if (curCap + jug2Capacity <= totCap && visited.find(curCap + jug2Capacity) == visited.end())
        {
            q.push(curCap + jug2Capacity);
            visited.insert(curCap + jug2Capacity);
        }
        if (curCap - jug2Capacity >= 0 && visited.find(curCap - jug2Capacity) == visited.end())
        {
            q.push(curCap - jug2Capacity);
            visited.insert(curCap - jug2Capacity);
        }
    }
    return false;
}

int main()
{
    cout << canMeasureWater(2, 6, 5);
}