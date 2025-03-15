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

vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
{
    vector<int> ans(queries.size(), 0);

    vector<pair<int, int>> q;
    for (int i = 0; i<queries.size(); i++) {
        q.push_back({queries[i], i});
    }

    sort(q.begin(), q.end());

    vector<pair<int, int>> arr;
    for (vector<int> &i : items) {
        arr.push_back({i[0], i[1]});
    }

    sort(arr.begin(), arr.end());

    int cur_beauty = 0;
    int cur_index = 0;

    for (int i=0; i<q.size(); i++) {
        int ind = q[i].second;
        int price = q[i].first;

        for (; cur_index < arr.size(); cur_index++) {
            if (arr[cur_index].first > price) {
                break;
            }
            cur_beauty = max(cur_beauty, arr[cur_index].second);
        }
        ans[ind] = cur_beauty;
    }
    return ans;
}

signed main()
{

    vector<vector<int>> items = {{1,2},{3,2},{2,4},{5,6},{3,5}};
    vector<int> queries = {1, 2, 3, 4, 5, 6};

    vector<int> ans = maximumBeauty(items, queries);
    for (int &i : ans) cout << i << " ";
    cout << endl;
}