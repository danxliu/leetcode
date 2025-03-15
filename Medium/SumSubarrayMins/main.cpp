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

int sumSubarrayMins(vector<int> &arr) {
    //dp[i][j] is minimum num in subarray (i, j) inclusive
    int n = arr.size();
    vector<int> left(n, -1);
    vector<int> right(n, n);
    
    stack<int> st;

    for (int i=0; i<n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            left[i] = st.top();
        }

        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            right[i] = st.top();
        }
        st.push(i);
    }

    long long ans = 0;
    for (int i=0; i<n; i++) {
        ans += ((i - left[i]) * (right[i] - i)) % (long long)(1e9 + 7) * arr[i];
        ans %= (long long)(1e9 + 7);
    }
    
    return ans;
}

signed main() {
    vector<int> arr = {11,81,94,43,3};
    cout << sumSubarrayMins(arr);
}
