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

vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < asteroids.size(); i++)
    {
        if (dq.empty() && asteroids[i] < 0)
            ans.push_back(asteroids[i]);
        else if (asteroids[i] < 0)
        {
            while (!dq.empty() && dq.back() < -1 * asteroids[i])
            {
                dq.pop_back();
            }
            if (dq.back() == -1 * asteroids[i])
            {
                dq.pop_back();
            }
            else if (dq.empty())
                ans.push_back(asteroids[i]);
        }
        else
        {
            dq.push_back(asteroids[i]);
        }
    }
    while (!dq.empty())
    {
        ans.push_back(dq.front());
        dq.pop_front();
    }
    return ans;
}

signed main()
{
    vector<int> asteroids = {10, 2, -5};
    vector<int> ans = asteroidCollision(asteroids);
    for (int &i : ans)
        cout << i << " ";
    cout << endl;
}