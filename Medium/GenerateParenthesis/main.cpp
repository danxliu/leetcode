#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct qinfo {
        string curSeq;
        int left;
        int right;
    };
    vector<string> generateParenthesis(int n) {
        queue<qinfo> q;
        vector<string> ans;
        qinfo start = {"", n, n};
        q.push(start);
        while (!q.empty())
        {
            qinfo cur = q.front();
            q.pop();
            if (cur.left == 0 && cur.right == 0)
            {
                ans.push_back(cur.curSeq);
            }
            if (cur.left <= cur.right)
            {
                if (cur.left > 0) q.push({cur.curSeq + "(", cur.left-1, cur.right});
                if (cur.right > 0) q.push({cur.curSeq + ")", cur.left, cur.right-1});
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.generateParenthesis(3);
    for (int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}