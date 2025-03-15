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

struct children
{
    int leftChild;
    int rightChild;
};

TreeNode *helper(int curNode, map<int, children> &mp) {
    TreeNode *cur = new TreeNode(curNode);
    if (!mp.count(curNode)) {
        return cur;
    }

    if (mp[curNode].leftChild != -1) {
        cur->left = helper(mp[curNode].leftChild, mp);
    }
    if (mp[curNode].rightChild != -1) {
        cur->right = helper(mp[curNode].rightChild, mp);
    }
    return cur;
}

TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
{
    map<int, children> mp;

    set<int> nodes;
    for (vector<int> &i : descriptions) {
        nodes.insert(i[0]);
        nodes.insert(i[1]);
    }

    for (vector<int> &i : descriptions)
    {
        int parent = i[0];
        int child = i[1];
        nodes.erase(child);
        int isLeft = i[2];
        if (!mp.count(parent))
            mp[parent] = {-1, -1};
        if (isLeft)
            mp[parent].leftChild = child;
        else
            mp[parent].rightChild = child;
    }

    int parent = *nodes.begin();

    return helper(parent, mp);
}

signed main()
{
    vector<vector<int>> descriptions = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
    TreeNode *node = createBinaryTree(descriptions);
}