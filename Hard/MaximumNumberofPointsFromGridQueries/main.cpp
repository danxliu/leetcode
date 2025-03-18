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

struct state {
    int r;
    int c;
    int v;
    bool operator<(const state& o) const {
        return v > o.v;
    }
};
vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    vector<int> ans;
    map<int, int> queryToVal;
    vector<int> sortedQueries = queries;
    sort(sortedQueries.begin(), sortedQueries.end());

    int n = grid.size();
    int m = grid[0].size();

    int dr[4] = {0, 1, -1, 0};
    int dc[4] = {1, 0, 0, -1};
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    priority_queue<state> pq;
    int count = 0;
    pq.push(state{0, 0, grid[0][0]});
    vis[0][0] = true;
    for (int &query : sortedQueries) {
        while (!pq.empty()) {
            state cur = pq.top();
            if (cur.v >= query) {
                break;
            }
            pq.pop();
            count++;

            for (int i=0; i<4; i++) {
                int nr = cur.r + dr[i];
                int nc = cur.c + dc[i];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (vis[nr][nc]) continue;
                vis[nr][nc] = true;
                state next = state{nr, nc, grid[nr][nc]};
                pq.push(next);
            }
        }
        queryToVal[query] = count;
    }

    for (int &query : queries) {
        ans.push_back(queryToVal[query]);
    }

    return ans;
}

signed main() {
}