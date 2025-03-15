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

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    vector<vector<pair<int, int>>> children(n, vector<pair<int, int>>());

    for (int i=0; i<manager.size(); i++) {
        if (manager[i] == -1) continue;
        children[manager[i]].push_back({i, informTime[manager[i]]});
    }

    vector<bool> vis(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, headID});
    vis[headID] = true;

    int ans = 0;
    while (!q.empty()) {
        int time = q.top().first;
        int id = q.top().second;
        ans = max(time, ans);

        q.pop();
        for (int i=0; i<children[id].size(); i++) {
            int next = children[id][i].first;
            int itime = children[id][i].second;
            if (vis[next]) continue;
            vis[next] = true;
            q.push({time + itime, next});
        }
    }
    return ans;
}

signed main()
{
    vector<int> manager = {2,2,-1,2,2,2};
    vector<int> informTime = {0,0,1,0,0,0};
    cout << numOfMinutes(6, 2, manager, informTime) << endl;
}