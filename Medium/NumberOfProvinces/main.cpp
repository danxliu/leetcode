#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited;
        for (int i=0; i<isConnected.size(); i++)
        {
            visited.push_back(0);
        }
        int numProvinces = 1;
        for (int i=0; i<isConnected.size(); i++)
        {
            if (!visited[i])
            {
                visited[i] = numProvinces;
                queue<int> q;
                q.push(i);
                while (!q.empty())
                {
                    int cur = q.front();
                    q.pop();
                    for (int j = 0; j<isConnected[cur].size(); j++)
                    {
                        if (isConnected[cur][j] && !visited[j] && j != cur)
                        {
                            visited[j] = numProvinces;
                            q.push(j);
                        }
                    }
                }
                numProvinces++;
            }
        }
        return numProvinces-1;
    }
};

int main()
{
    Solution s;
    vector< vector<int > > isConnected = {{1,0,0},{0,1,0},{0,0,1}};
    cout << s.findCircleNum(isConnected) << endl;
}