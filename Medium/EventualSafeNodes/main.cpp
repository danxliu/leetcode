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

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    // Graph is outward paths
    int n = graph.size();
    int indegree[n];
    for (int i = 0; i < n; i++)
        indegree[i] = 0;
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int &j : graph[i])
        {
            indegree[i]++;
            adj[j].push_back(i);
        }
    }
    queue<int> q;
    bool safe[n];
    for (int i = 0; i < n; i++)
    {
        safe[i] = false;
        if (!indegree[i])
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        safe[cur] = true;
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int neighbor = adj[cur][i];
            indegree[neighbor]--;
            if (!indegree[neighbor])
            {
                q.push(neighbor);
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (safe[i])
            ans.push_back(i);
    }
    return ans;
}

signed main()
{
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> ans = eventualSafeNodes(graph);
    for (int &i : ans)
        cout << i << " ";
    cout << endl;
}