#include <bits/stdc++.h>
using namespace std;

// --------------------Leetcode-Data-Structures--------------------

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createListNode(vector<int> nums) {
  ListNode *head = new ListNode();
  ListNode *temp = head;
  for (int i = 0; i < nums.size(); i++) {
    head->val = nums[i];
    if (i != nums.size() - 1) {
      head->next = new ListNode();
      head = head->next;
    }
  }
  return temp;
}

void printListNode(ListNode *head) {
  ListNode *cur = head;
  while (cur) {
    cout << cur->val << ' ';
    cur = cur->next;
  }
  cout << endl;
  return;
}

int sizeListNode(ListNode *head) {
  int ans = 0;
  ListNode *cur = head;
  while (cur) {
    cur = cur->next;
    ans++;
  }
  return ans;
}

// --------------------Snippet-Ends--------------------------------

void recurse(vector<int> &candidates, vector<int> &cur, int ind, int csum, int target, vector<vector<int>> &ans) {
    if (csum > target || ind > candidates.size()) return;
    if (csum == target) {
        ans.push_back(cur);
        return;
    }
    for (int i=ind; i<candidates.size(); i++) {
        if (i-1 >= ind && candidates[i] == candidates[i - 1]) continue;
        cur.push_back(candidates[i]);
        recurse(candidates, cur, i+1, csum + candidates[i], target, ans);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    vector<int> cur;
    recurse(candidates, cur, 0, 0, target, ans);
    return ans;
}

signed main() {}
