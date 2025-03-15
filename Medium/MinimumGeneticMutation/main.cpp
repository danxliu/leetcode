#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    char d[4] = {'A', 'C', 'G', 'T'};
    int minMutation(string start, string end, vector<string>& bank) {
        map <string, bool> visited;
        for (int i =0; i<bank.size(); i++)
        {
            visited.insert({bank[i], false});
        }
        visited.insert({start, true});
        queue<pair<string, int> > q;
        q.push({start, 0});
        while (!q.empty())
        {
            pair<string, int> cur = q.front();
            q.pop();
            if (cur.first == end)
            {
                return cur.second;
            }
            for (int i=0; i<cur.first.size(); i++)
            {
                for (int j=0; j<4; j++)
                {
                    string ns = cur.first;
                    ns[i] = d[j];
                    if (visited.find(ns) != visited.end() && !visited[ns])
                    {
                        visited[ns] = true;
                        q.push({ns, cur.second + 1});
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<string> bank = {"AAAACCCC","AAACCCCC","AACCCCCC"};
    string start = "AAAAACCC";
    string end = "AACCCCCC";
    cout << s.minMutation(start, end, bank);
}