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

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    map<string, vector<string>> adjmat;

    for (vector<string> &account : accounts) {
        for (int i=2; i<account.size(); i++) {
            adjmat[account[1]].push_back(account[i]);
            adjmat[account[i]].push_back(account[1]);
        }
    }

    vector<vector<string>> ans;
    queue<string> q;
    set<string> vis;
    for (vector<string> &account: accounts) {
        string name = account[0];
        if (vis.count(account[1])) continue;

        q.push(account[1]);
        vis.insert(account[1]);
        vector<string> a;
        a.push_back(account[0]);
        a.push_back(account[1]);
        while(!q.empty()) {
            string cur = q.front();
            q.pop();
            for (string &email : adjmat[cur]) {
                if (vis.count(email)) continue;
                vis.insert(email);
                a.push_back(email);
                q.push(email);
            }
        }
        sort(a.begin()+1, a.end());
        ans.push_back(a);
    }
    return ans;

}

signed main() {

}