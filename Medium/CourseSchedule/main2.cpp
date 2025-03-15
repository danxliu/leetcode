#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


class Solution {
public:
    map<int, vector<int> > classToPres;
    vector<bool> visitedClasses;
    vector<bool> finishedClasses;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
            visitedClasses.push_back(false);
            if (classToPres.find(i) == classToPres.end())
            {
                finishedClasses.push_back(true);
            }
            else
            {
                finishedClasses.push_back(false);
            }
        }

        for (int i=0; i<numCourses; i++)
        {
            if (!finishedClasses[i])
            {
                for (int j=0; j<visitedClasses.size(); j++)
                {
                    visitedClasses[j] = false;
                }
                finishedClasses[i] = helper(i);
            }
        }

        for (int i=0; i<finishedClasses.size(); i++)
        {
            if(!finishedClasses[i])
            {
                return false;
            }
        }
        return true;
    }

    bool helper(int cur)
    {
        if (finishedClasses[cur])
        {
            return true;
        }
        if (visitedClasses[cur])
        {
            return false;
        }
        visitedClasses[cur] = true;
        bool ans = true;
        for (int i=0; i<classToPres[cur].size(); i++)
        {
            finishedClasses[classToPres[cur][i]] = helper(classToPres[cur][i]);
            ans = ans && finishedClasses[classToPres[cur][i]];
            if (!ans)
            {
                return ans;
            }
        }
        return ans;
    }
};

int main()
{
    int numCourses = 7;
    vector<vector<int> > prerequisites = {{1,0}};
    Solution s;
    cout << s.canFinish(numCourses, prerequisites) << endl; 
}