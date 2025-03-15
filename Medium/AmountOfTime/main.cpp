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

void traverseTree(TreeNode *root, map<int, vector<int>> &adjmat) {
  int val = root->val;
  if (root->left) {
    int nval = root->left->val;
    if (!adjmat.count(val)) adjmat[val] = {};
    adjmat[val].push_back(nval);
    
    if (!adjmat.count(nval)) adjmat[nval] = {};
    adjmat[nval].push_back(val);
    traverseTree(root->left, adjmat);
  }
  if (root->right) {
    int nval = root->right->val;
    if (!adjmat.count(val)) adjmat[val] = {};
    adjmat[val].push_back(nval);
    
    if (!adjmat.count(nval)) adjmat[nval] = {};
    adjmat[nval].push_back(val);
    traverseTree(root->right, adjmat);
  }
}

int amountOfTime(TreeNode* root, int start) {
  map<int, vector<int>> adjmat;
  traverseTree(root, adjmat);

  set<int> visited;
  queue<pair<int, int>> q;
  q.push({start, 0});
  visited.insert(0);

  int ans = 0;
  while (!q.empty()) {
    int cnode = q.front().first;
    int ctime = q.front().second;
    ans = max(ans, ctime);
    q.pop();

    for (int &i : adjmat[cnode]) {
      if (!visited.count(i)) {
        visited.insert(i);
        q.push({i, ctime + 1});
      }
    }
  }
  return ans;
}

signed main()
{

}
