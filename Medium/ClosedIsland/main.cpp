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

void floodfill(vector<vector<int>> &grid, pair<int, int> start)
{
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    queue<pair<int, int>> q;
    grid[start.first][start.second] = 1;
    q.push(start);

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> next = {cur.first + dx[i], cur.second + dy[i]};
            if (next.first < 0 || next.second < 0 || next.first >= grid.size() || next.second >= grid[0].size())
                continue;
            if (grid[next.first][next.second] != 0)
                continue;
            grid[next.first][next.second] = 1;
            q.push(next);
        }
    }
}

int closedIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    for (int i=0; i<n; i++) {
        if (grid[i][0] == 0) floodfill(grid, {i, 0});
        if (grid[i][m-1] == 0) floodfill(grid, {i, m-1});
    }
    for (int i=0; i<m; i++) {
        if (grid[0][i] == 0) floodfill(grid, {0, i});
        if (grid[n-1][i] == 0) floodfill(grid, {n-1, i});
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == 0) {
                floodfill(grid, {i, j});
                ans++;
            }
        }
    }
    return ans;
}

signed main()
{
}