#include <algorithm>
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

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    if (n == 1) {
        return time[0];
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (time, index)
    map<int, vector<int>> parents; // parents[i] represent parents of node i
    map<int, int> outdegree; // outdegree[i] represents outdegree of node i

    for (vector<int> &i : relations) {
        int in = i[0];
        int out = i[1];
        outdegree[out]++;
        parents[in].push_back(out);
    }

    int curtime = 0;
    // Push all nodes with outdegree 0
    for (int i=1; i<=n; i++) {
        if (!outdegree.count(i) || !outdegree[i]) {
            pq.push({curtime + time[i-1], i});
        }
    }
    while(!pq.empty()) {
        // Pop from min heap
        curtime = pq.top().first;
        int curid = pq.top().second;
        pq.pop();

        // Subtract outdegree
        for (int &parent : parents[curid]) {
            outdegree[parent]--;
            if (outdegree[parent] == 0) {
                pq.push({curtime + time[parent-1], parent});
            }
        }
    }

    return curtime;
}

signed main()
{
    vector<vector<int>> relations = {{1,3},{2,3}};
    vector<int> time = {3, 2, 5};

    cout << minimumTime(3, relations, time) << endl;
}
