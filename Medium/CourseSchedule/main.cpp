#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    map<int, int > classToPres;
    vector<int> finishedClasses;
    vector<int> visitedClasses;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i=0; i<numCourses; i++)
        {
            finishedClasses.push_back(false);
        }
        for (int i=0; i<prerequisites.size(); i++)
        {
            classToPres.insert({prerequisites[i][0], prerequisites[i][1]});
        }
        for (int i=0; i < numCourses; i++)
        {
            finishedClasses.push_back(false);
            visitedClasses.push_back(false);
        }
        for (int i=0; i < numCourses; i++)
        {
            cout << "currently on: " << i << endl;
            cout << "requires: " << classToPres[i] << endl;
            if (!finishedClasses[i])
            {
                int c = helper(i);
                cout << "result: " << i << " " << c << endl;
                for (int j=0; j<finishedClasses.size(); j++)
                {
                    cout << finishedClasses[j];
                }
                cout << endl;
                if (c <= 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    int helper(int cur)
    {
        cout << "helper checking: " << cur << endl;
        //doesn't have a prereq or is finished with it
        if (classToPres.find(cur) == classToPres.end() || finishedClasses[classToPres[cur]])
        {
            finishedClasses[cur] = true;
            return 1;
        }
        // already visited the class and tried to complete it, then it is a loop
        if (visitedClasses[cur] && !finishedClasses[cur])
        {
            return -100000;
        }
        visitedClasses[cur] = true;
        // has an unfinished prereq, needs to be finished
        return helper(classToPres[cur]);
    }
};

int main()
{
    int numCourses = 5;
    vector<vector<int> > prerequisites = {{2,0},{1,0},{3,1},{3,2},{1,3}};
    Solution s;
    cout << s.canFinish(numCourses, prerequisites) << endl; 
}