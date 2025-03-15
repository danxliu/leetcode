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
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 1e9));
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++)
        {
            if (mat[i][j] == 0)
            {
                ans[i][j] = 0;
                q.push({0, {i, j}});
            }
        }
    }
    while (!q.empty())
    {
        int dist = q.front().first;
        pair<int, int> cur = q.front().second;
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> next = {cur.first + dx[i], cur.second + dy[i]};
            if (next.first < 0 || next.second < 0 || next.first >= mat.size() || next.second >= mat[next.first].size() || ans[next.first][next.second] <= dist + 1)
                continue;
            ans[next.first][next.second] = dist + 1;
            q.push({dist + 1, {next.first, next.second}});
        }
    }
    return ans;
}

signed main()
{
}