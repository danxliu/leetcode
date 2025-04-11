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
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";
    return;
}

// --------------------Snippet-Ends--------------------------------

int find(vector<int> &arr, int a) {
    if (arr[a] < 0) return a;

    return arr[a] = find(arr, arr[a]);
}

void unite(vector<int> &arr, vector<int> &weight, int a, int b, int w) {
    int pa = find(arr, a);
    int pb = find(arr, b);

    if (pa == pb) {
        weight[pa] &= w;
        return;
    }
    
    // based on size
    if (arr[pb] > arr[pa]) {
        arr[pa] += arr[pb];
        arr[pb] = pa;
        weight[pa] &= w;
        weight[pa] &= weight[pb];
    } else {
        arr[pb] += arr[pa];
        arr[pa] = pb;
        weight[pb] &= w;
        weight[pb] &= weight[pa];
    }
}

vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    vector<int> arr;
    vector<int> weight;
    for (int i=0; i<n; i++) {
        arr.push_back(-1);
        weight.push_back(~0);
    }

    for (vector<int> &edge : edges) {
        unite(arr, weight, edge[0], edge[1], edge[2]);
    }

    vector<int> ans;

    for (vector<int> &q: query) {
        int p0 = find(arr, q[0]);
        int p1 = find(arr, q[1]);
        if (p0 != p1) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(weight[p0]);
        }
    }
    return ans;
}