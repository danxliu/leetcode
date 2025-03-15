#include <bits/stdc++.h>
using namespace std;

// --------------------Leetcode-Data-Structures--------------------

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createListNode(vector<int> nums)
{
    ListNode *head = new ListNode();
    ListNode *temp = head;
    for (int i = 0; i < nums.size(); i++)
    {
        head->val = nums[i];
        if (i != nums.size() - 1)
        {
            head->next = new ListNode();
            head = head->next;
        }
    }
    return temp;
}

void printListNode(ListNode *head)
{
    ListNode *cur = head;
    while (cur)
    {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
    return;
}

int sizeListNode(ListNode *head)
{
    int ans = 0;
    ListNode *cur = head;
    while (cur)
    {
        cur = cur->next;
        ans++;
    }
    return ans;
}

// --------------------Snippet-Ends--------------------------------

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> ans(n, vector<int>(m, -1));
    queue<pair<pair<int, int>, int>> q;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat[i][j] == 0) {
                ans[i][j] = 0;
                q.push({{i, j}, 0});
            }
        }
    }

    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};

    while (!q.empty()) {
        pair<int, int> cur_loc = q.front().first;
        int cur_dist = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            pair<int, int> next_loc = {cur_loc.first + dx[i], cur_loc.second + dy[i]};
            if (next_loc.first < 0 || next_loc.first >= n || next_loc.second <0 || next_loc.second >= m) continue;
            if (ans[next_loc.first][next_loc.second] != -1) continue;

            ans[next_loc.first][next_loc.second] = cur_dist + 1;
            q.push({next_loc, cur_dist + 1});
        }
    }
    return ans;
}

signed main()
{
}