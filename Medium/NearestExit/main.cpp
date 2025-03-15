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

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
    vector<vector<bool>> vis(maze.size(), vector<bool>(maze[0].size(), false));
    queue<pair<pair<int, int>, int>> q;
    q.push({{entrance[0], entrance[1]}, 0});
    vis[entrance[0]][entrance[1]] = true;

    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};

    while (!q.empty())
    {
        pair<int, int> cur_loc = q.front().first;
        int cur_dist = q.front().second;
        q.pop();

        if (cur_loc.first == 0 || cur_loc.first == maze.size() - 1 || cur_loc.second == 0 || cur_loc.second == maze[0].size() - 1)
        {
            if (cur_loc.first != entrance[0] || cur_loc.second != entrance[1])
            {
                return cur_dist;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> next_loc = {cur_loc.first + dx[i], cur_loc.second + dy[i]};
            if (next_loc.first < 0 || next_loc.second < 0 || next_loc.first >= maze.size() || next_loc.second >= maze[0].size())
                continue;
            if (vis[next_loc.first][next_loc.second] || maze[next_loc.first][next_loc.second] == '+')
                continue;
            vis[next_loc.first][next_loc.second] = true;
            int next_dist = cur_dist + 1;
            q.push({next_loc, next_dist});
        }
    }
    return -1;
}

signed main()
{
}