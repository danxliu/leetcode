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

void createGraph(TreeNode *root, int parent, map<int, vector<int>> &adjList)
{
    if (parent != -1)
    {
        adjList[root->val].push_back(parent);
    }
    if (root->left)
    {
        adjList[root->val].push_back(root->left->val);
        createGraph(root->left, root->val, adjList);
    }
    if (root->right)
    {
        adjList[root->val].push_back(root->right->val);
        createGraph(root->right, root->val, adjList);
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    // turn into graph and bfs
    vector<int> ans;
    map<int, vector<int>> adjList;
    set<int> vis;
    createGraph(root, -1, adjList);
    queue<pair<int, int>> q;
    q.push({target->val, 0});
    vis.insert(target->val);
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.second == k)
            ans.push_back(cur.first);
        for (int &i : adjList[cur.first])
        {
            if (vis.find(i) == vis.end())
            {
                vis.insert(i);
                q.push({i, cur.second + 1});
            }
        }
    }
    return ans;
}

signed main()
{
}