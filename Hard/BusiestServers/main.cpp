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

vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    set<int> available;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> loaded; // servers loaded, first is finish time, second is server index
    map<int, int> server_to_requests; // map from server id to number of requests

    for (int i=0; i<k; i++) available.insert(i);

    for (int i=0; i<arrival.size(); i++) {
        // Pop all of the loaded server that have finish times <= arrival[i]
        while (!loaded.empty()) {
            pair<int, int> server = loaded.top();
            if (server.first <= arrival[i]) {
                available.insert(server.second);
                loaded.pop();
            } else {
                // Everything after is guaranteed to have a later finish time
                break;
            }
        }

        if (!available.size()) {
            continue; // drop request
        }

        // Find the next available server
        auto it = available.lower_bound(i%k);
        if (it == available.end()) it = available.begin(); // circle back to starting server

        // *it is the server that is chosen
        loaded.push({arrival[i] + load[i], *it});
        server_to_requests[*it] += 1;
        available.erase(it);
    }

    int mx = 0;
    vector<int> ans;

    for (auto it = server_to_requests.begin(); it != server_to_requests.end(); it++) {
        if (it->second > mx) {
            ans = {it->first};
            mx = it->second;
        }
        else if (it->second == mx) {
            ans.push_back(it->first);
        }
    }

    return ans;
}

signed main()
{
    vector<int> arrival = {1, 2, 3, 4, 5};
    vector<int> load = {5, 2, 3, 3, 3};
    vector<int> ans = busiestServers(3, arrival, load);
    for (int &i : ans) {
        cout << i << " ";
    }
    cout << endl;
}