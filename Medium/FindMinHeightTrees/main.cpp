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

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
  //Idea: First push in all vertices with only one edge into stack
  //move along the edge to neighboring nodes, check if they only have one other unvisited edge; if they do, push that to the stack
  //continue until there are no nodes left, and output the ones with the furthest distance
  
  if (edges.size() == 0) {
    return vector<int>(1, 0);
  }
  
  //convert edges to an adjacency list
  vector<vector<int>> adjList(n, vector<int>());
  vector<int> degree(n, 0);
  for (vector<int> &i : edges) {
    adjList[i[0]].push_back(i[1]);
    adjList[i[1]].push_back(i[0]);
    degree[i[0]]++;
    degree[i[1]]++;
  }
  
  vector<int> dist(n, 0);
  vector<bool> vis(n, false);
  queue<int> q;

  //find starting nodes
  for (int i=0; i<degree.size(); i++) {
    if (degree[i] == 1) {
      q.push(i);
      vis[i] = true;
      dist[i] = 0;
      degree[i] = 0;
    }
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int i=0; i<adjList[cur].size(); i++) {
      int next = adjList[cur][i];
      degree[next]--;
      if (vis[next]) continue;
      dist[next] = max(dist[cur] + 1, dist[next]);
      //check next node neighbors to make sure they only have 1 or 0 unvisited edges
      if (degree[next] == 1) {
        vis[next] = true;
        q.push(next);
      }
    }
  }

  int mx = 0;
  for (int &i : dist) {
    mx = max(i, mx);
  }

  vector<int> ans;
  for (int i=0; i<dist.size(); i++) {
    if (dist[i] == mx) {
      ans.push_back(i);
    }
  }
  
  return ans;
}
