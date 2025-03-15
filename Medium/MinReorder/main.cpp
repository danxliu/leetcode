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

int minReorder(int n, vector<vector<int>> &connections)
{
    vector<vector<pair<int, int>>> paths(n, vector<pair<int, int>>());

    for (vector<int> &i : connections)
    {
        int a = i[0];
        int b = i[1];
        paths[b].push_back({a, 0});
        paths[a].push_back({b, 1});
    }

    vector<bool> vis(n, false);
    stack<int> st;
    st.push(0);
    vis[0] = true;
    int ans = 0;
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        for (int i=0; i<paths[cur].size(); i++) {
            int next = paths[cur][i].first;
            if (vis[next]) continue;
            vis[next] = true;
            ans += paths[cur][i].second;
            st.push(next);
        }
    }
    return ans;
}

signed main()
{
    vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    int n = 6;
    cout << minReorder(n, connections) << endl;
}