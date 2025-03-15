#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

vector<int> getOrder(vector<vector<int>> &tasks)
{
    sort(tasks.begin(), tasks.end(), compare);
    multiset<pair<int, pair<int, int>>> enqTasks;
    enqTasks.insert({tasks[0][1], {tasks[0][0], 0}});
    for (int i = 0; i < tasks.size();)
    {
        pair<int, pair<int, int>> cur = *(enqTasks.begin());
        enqTasks.erase(cur);
        cout << cur.second.second;
        int t = cur.first;
        int et = cur.first + cur.second.first;
        while (tasks[i][0] < et)
        {
            enqTasks.insert({tasks[i][0], {tasks[i][1], i}});
            i++;
        }
        if (enqTasks.empty())
        {
            i++;
            enqTasks.insert({tasks[i][0], {tasks[i][1], i}});
        }
    }
}

int main()
{
}