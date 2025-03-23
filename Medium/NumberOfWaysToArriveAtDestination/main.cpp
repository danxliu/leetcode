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

int countPaths(int n, vector<vector<int>>& roads) {
    const long long mod = (long long)(1e9+7);

    vector<vector<pair<int, int>>> adjmat(n, vector<pair<int, int>>());

    for (vector<int> &i : roads) {
        adjmat[i[0]].push_back({i[1], i[2]});
        adjmat[i[1]].push_back({i[0], i[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // first: dist, second: node
    vector<pair<int, int>> dist(n, {-1, -1}); // first: dist, second: count

    pq.push({0, 0});
    dist[0] = {0, 1};

    while (!pq.empty()) {
        int cn = pq.top().second;
        int cd = pq.top().first;
        pq.pop();

        for (int i=0; i<adjmat[cn].size(); i++) {
            int nn = adjmat[cn][i].first;
            int nd = cd + adjmat[cn][i].second;

            if (dist[nn].first == -1 || dist[nn].first < nd) {
                dist[nn].first = nd;
                dist[nn].second = dist[cn].second;
                pq.push({nd, nn});
            } else if (dist[nn].first == nd) {
                dist[nn].second++;
                pq.push({nd, nn});
            }
        }
    }

    return dist[n-1].second % mod;
}

signed main()
{

}