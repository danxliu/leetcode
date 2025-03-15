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

struct state
{
    int node;
    int len;
    bool color;
};

vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
{
    vector<vector<int>> dist(2, vector<int>(n, -1));
    vector<vector<int>> re(n, vector<int>());
    vector<vector<int>> be(n, vector<int>());

    for (int i = 0; i < redEdges.size(); i++)
    {
        re[redEdges[i][0]].push_back(redEdges[i][1]);
    }
    for (int i = 0; i < blueEdges.size(); i++)
    {
        be[blueEdges[i][0]].push_back(blueEdges[i][1]);
    }

    queue<state> q;
    q.push(state{0, 0, false});
    q.push(state{0, 0, true});
    dist[0][0] = 0;
    dist[1][0] = 0;

    while (!q.empty())
    {
        state cur = q.front();
        q.pop();

        if (cur.color)
        {
            for (int i = 0; i < re[cur.node].size(); i++)
            {
                state next = state{re[cur.node][i], cur.len + 1, !cur.color};
                if (dist[next.color][next.node] == -1 || dist[next.color][next.node] > next.len)
                {
                    dist[next.color][next.node] = next.len;
                    q.push(next);
                }
            }
        }
        else
        {
            for (int i = 0; i < be[cur.node].size(); i++)
            {
                state next = state{be[cur.node][i], cur.len + 1, !cur.color};
                if (dist[next.color][next.node] == -1 || dist[next.color][next.node] > next.len)
                {
                    dist[next.color][next.node] = next.len;
                    q.push(next);
                }
            }
        }
    }
    vector<int> ans;
    for (int i=0; i<n; i++) {
        if (dist[0][i] == -1 && dist[1][i] == -1) ans.push_back(-1);
        else if (dist[0][i] == -1) ans.push_back(dist[1][i]);
        else if (dist[1][i] == -1) ans.push_back(dist[0][i]);
        else ans.push_back(min(dist[0][i], dist[1][i]));
    }
    return ans;
}

signed main()
{
    vector<vector<int>> redEdges = {{0,1},{1,2},{2,3},{3,4}};
    vector<vector<int>> blueEdges = {{1,2},{2,3},{3,1}};
    vector<int> ans = shortestAlternatingPaths(5, redEdges, blueEdges);
    for (int &i : ans) {
        cout << i << " ";
    }
    cout << endl;
}