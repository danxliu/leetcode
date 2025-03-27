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

int minimumIndex(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (int &i : nums) mp[i]++;

    int mx = -1;
    int num = 0;
    for (auto it = mp.begin(); it!=mp.end(); it++) {
        if (it->second > num) {
            mx = it->first;
            num = it->second;
        }
    }

    // prefix sum
    vector<int> ps;
    ps.push_back(0);
    for (int &i : nums) {
        ps.push_back(ps.back() + (i == mx));
    }

    for (int i=1; i<ps.size(); i++) {
        if (ps[i] * 2 > i && (ps.back() - ps[i]) * 2 > ps.size() - i - 1) return i-1;
    }

    return -1;

}


int main() {

}