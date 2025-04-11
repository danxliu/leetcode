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

int countCompleteComponents(int n, vector<vector<int>>& edges) {
    unordered_set<int> vis;
    queue<int> q;

    vector<vector<int>> adjmat(n, vector<int>());
    for (vector<int> &i : edges) {
        adjmat[i[0]].push_back(i[1]);
        adjmat[i[1]].push_back(i[0]);
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (vis.count(i)) continue;

        int nodes = 0;
        int edges = 0;

        q.push(i);
        vis.insert(i);
        while (!q.empty()) {
            int cur = q.front();
            nodes++;
            q.pop();

            edges += adjmat[cur].size();
            for (int j=0; j<adjmat[cur].size(); j++) {
                int next = adjmat[cur][j];
                if (vis.count(next)) continue;
                vis.insert(next);
                q.push(next);
            }
        }

        if (nodes * (nodes-1) == edges)
            cnt++;
    }

    return cnt;
}

signed main()
{

}