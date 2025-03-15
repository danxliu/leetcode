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

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    vis[0][0] = true;
    q.push({{0, 0}, 0});


    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[8] = {1, -1, 1, -1, -1, 0, 0, 1};

    while (!q.empty()) {
        pair<int, int> cur_loc = q.front().first;
        int cur_dist = q.front().second;
        q.pop();
        if (cur_loc.first == n-1 && cur_loc.second == m-1) return cur_dist;

        for (int i=0; i<8; i++) {
            pair<int, int> next_loc = {cur_loc.first + dx[i], cur_loc.second + dy[i]};
            if (next_loc.first < 0 || next_loc.second < 0 || next_loc.first >= n || next_loc.second >= m) continue;
            if (vis[next_loc.first][next_loc.second] || grid[next_loc.first][next_loc.second] == 1) continue;
            vis[next_loc.first][next_loc.second] = true;
            q.push({next_loc, cur_dist + 1});
        }
    }
    return -1;
}

signed main()
{
}