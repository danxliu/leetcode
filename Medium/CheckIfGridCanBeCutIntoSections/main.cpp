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

int cuts(vector<pair<int, int>> &nums) {
    int n = 0;
    int end = nums[0].second;
    for (int i=1; i<nums.size(); i++) {
        if (nums[i].first >= end) n++;
        end = max(end, nums[i].second);
    }
    return n;
}

bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    vector<pair<int, int>> x;
    vector<pair<int, int>> y;
    for (vector<int> &i : rectangles) {
        x.push_back({i[0], i[2]});
        y.push_back({i[1], i[3]});
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    return (cuts(x) >= 2 || cuts(y) >= 2);
}

int main() {

}