#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    map<int, vector<int> > classToPres;
    vector<bool> visited;
    vector<bool> finished;
    vector<int> path;
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        for (int i=0; i<prerequisites.size(); i++)
        {
            if (classToPres.find(prerequisites[i][0]) != classToPres.end())
            {
                classToPres[prerequisites[i][0]].push_back(prerequisites[i][1]);
            }
            else
            {
                vector<int> temp;
                temp.push_back(prerequisites[i][1]);
                classToPres.insert({prerequisites[i][0], temp});
            }
        }
        for (int i=0; i<numCourses; i++)
        {
            visited.push_back(false);
            if (classToPres.find(i) == classToPres.end())
            {
                finished.push_back(true);
                path.push_back(i);
            }
            else
            {
                finished.push_back(false);
            }
        }
        for (int i=0; i<numCourses; i++)
        {
            if (!finished[i])
            {
                for (int j=0; j<visited.size(); j++)
                {
                    visited[j] = false;
                }
                finished[i] = helper(i);
            }
        }
        for (int i=0; i<finished.size(); i++)
        {
            if(!finished[i])
            {
                vector<int> empty;
                return empty;
            }
        }
        return path;
    }
    bool helper(int cur)
    {
        if (finished[cur])
        {
            return true;
        }
        if (visited[cur])
        {
            return false;
        }
        visited[cur] = true;
        bool ans = true;
        for (int i=0; i<classToPres[cur].size(); i++)
        {
            finished[classToPres[cur][i]] = helper(classToPres[cur][i]);
            ans = ans && finished[classToPres[cur][i]];
            if (!ans)
            {
                return ans;
            }
        }
        path.push_back(cur);
        return ans;
    }
};

int main()
{
    int numCourses = 4;
    vector<vector<int> > prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    Solution s;
    vector<int> path = s.findOrder(numCourses, prerequisites);
    for (int i=0; i<path.size(); i++)
    {
        cout << path[i] << " ";
    } 
}