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

map<int, vector<TreeNode*>> dp;

vector<TreeNode*> allPossibleFBT(int n) {
  vector<TreeNode*> trees;
  if (n < 1 || n % 2 == 0) {
    return trees;
  }

  if (dp.count(n)) {
    return dp[n];
  }

  if (n == 1) {
    trees.push_back(new TreeNode(0));
    dp[n] = trees;
    return dp[n];
  }

  for (int i=0; i<n; i++) {
    vector<TreeNode*> leftTrees = allPossibleFBT(i);
    vector<TreeNode*> rightTrees = allPossibleFBT(n-i-1);
    for (int j=0; j<leftTrees.size(); j++) {
      for (int k=0; k<rightTrees.size(); k++) {
        TreeNode *tree = new TreeNode(0);
        tree->left = leftTrees[j];
        tree->right= rightTrees[j];
        trees.push_back(tree);
      }
    }
  }
  dp[n] = trees;
  return dp[n];
}

signed main()
{

}
