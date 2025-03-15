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

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<bool>> pacific(n, vector<bool>(m, false));
    vector<vector<bool>> atlantic(n, vector<bool>(m, false));

    queue<pair<int, int>> q;
    
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    // Find to pacific
    for (int i=0; i<n; i++) {
        q.push({i, 0});
        pacific[i][0] = true;
    }
    for (int i=0; i<m; i++) {
        q.push({0, i});
        pacific[0][i] = true;
    }
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            pair<int, int> next = {cur.first + dx[i], cur.second + dy[i]};
            if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m) continue;
            if (pacific[next.first][next.second]) continue;
            if (heights[next.first][next.second] < heights[cur.first][cur.second]) continue;
            pacific[next.first][next.second] = true;
            q.push(next);
        }
    }

    // Find to atlantic
    for (int i=0; i<n; i++) {
        q.push({i, m-1});
        atlantic[i][m-1] = true;
    }
    for (int i=0; i<m; i++) {
        q.push({n-1, i});
        atlantic[n-1][i] = true;
    }
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            pair<int, int> next = {cur.first + dx[i], cur.second + dy[i]};
            if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m) continue;
            if (atlantic[next.first][next.second]) continue;
            if (heights[next.first][next.second] < heights[cur.first][cur.second]) continue;
            atlantic[next.first][next.second] = true;
            q.push(next);
        }
    }

    vector<vector<int>> ans;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (atlantic[i][j] && pacific[i][j]) {
                ans.push_back({i, j});
            }
        }
    }
    return ans;
}

signed main()
{
}