#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        ans.assign(2000, vector<int>());
        if (root == NULL)
        {
            return ans;
        }
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        ans[0].push_back(root->val);
        while (!q.empty())
        {
            TreeNode *cur = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if (cur->left != NULL)
            {
                ans[lvl + 1].push_back(cur->left->val);
                q.push({cur->left, lvl + 1});
            }
            if (cur->right != NULL)
            {
                ans[lvl + 1].push_back(cur->right->val);
                q.push({cur->right, lvl + 1});
            }
        }
        vector<vector<int>> tans;
        for (int i=0; i<ans.size(); i++) {
            if (ans[i].size() > 0) {
                tans.push_back(ans[i]);
            }
        }
        return tans;
    }
};