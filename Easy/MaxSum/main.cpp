#include <bits/stdc++.h>
#include <queue>
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

int maxSum(vector<int> &nums) {
    map<int, priority_queue<int, vector<int>, greater<int>>> mx;
    for (int &i : nums) {
        // get maximum digit
        int m = 0;
        int c = i;
        while (c > 0) {
            m = max(m, c % 10);
            c /= 10;
        }
        if (!mx.count(m))
            mx[m] = {};
        mx[m].push(i);
    }

    int ans = -1;
    for (auto it = mx.begin(); it!=mx.end(); it++) {
        if (it->second.size() > 1) {
            int i = it->second.top();
            it->second.pop();
            int j = it->second.top();
            ans = max(ans, i + j);
        }
    }
    return ans;
}

signed main() {
    vector<int> nums = {51, 71, 17, 24, 42};
    cout << maxSum(nums) << endl;
}
