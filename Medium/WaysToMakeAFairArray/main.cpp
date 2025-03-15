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

int waysToMakeFair(vector<int> &nums) {
  vector<int> even;
  vector<int> odd;
  even.push_back(nums[0]);
  odd.push_back(nums[1]);
  for (int i = 2; i < nums.size(); i += 2) {
    even.push_back(nums[i] + even.back());
  }

  for (int i = 3; i < nums.size(); i += 2) {
    odd.push_back(nums[i] + odd.back());
  }

  int ans = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (i % 2 == 0) {
      // we remove an even number
      // prefix sum of numbers before i
      int odd_prev = (i / 2 - 1 >= 0) ? odd[i / 2 - 1] : 0;
      int even_prev = (i / 2 - 1 >= 0) ? even[i / 2 - 1] : 0;

      // prefix sum of numbers after i
      int odd_next = even.back() - even[i / 2];
      int even_next = odd.back() - odd_prev;
      ans += (odd_prev + odd_next) == (even_prev + even_next);
    } else {
      // we remove an odd number
      // prefix sum of numbers before i
      int odd_prev = ((i - 1) / 2 - 1 >= 0) ? odd[(i - 1) / 2 - 1] : 0;
      int even_prev = even[(i - 1) / 2];

      int odd_next = even.back() - even[(i - 1) / 2];
      int even_next = odd.back() - odd[(i - 1) / 2];
      ans += (odd_prev + odd_next) == (even_prev + even_next);
    }
  }

  return ans;
}

signed main() {
  vector<int> nums = {1};
  cout << waysToMakeFair(nums);
}
