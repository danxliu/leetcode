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

int countPalindromes(string s)
{
    int mod = 1e9+7;
    int n = s.size();

    vector<vector<vector<int>>> left_pair_count(n+1, vector<vector<int>>(10, vector<int>(10, 0)));
    vector<vector<vector<int>>> right_pair_count(n+1, vector<vector<int>>(10, vector<int>(10, 0)));
    vector<int> left_count(10, 0);
    vector<int> right_count(10, 0);

    for (int i=0; i<n; i++) {
        int cur = s[i] - '0';
        if (i > 0) {
            for (int j=0; j<10; j++) {
                for (int k=0; k<10; k++) {
                    left_pair_count[i][j][k] = left_pair_count[i-1][j][k];
                }
            }
        }
        for (int j=0; j<10; j++) {
            left_pair_count[i][j][cur] += left_count[j];
        }
        left_count[cur]++;
    }

    for (int i=n-1; i>=0; i--) {
        int cur = s[i] - '0';
        if (i < n-1) {
            for (int j=0; j<10; j++) {
                for (int k=0; k<10; k++) {
                    right_pair_count[i][j][k] = right_pair_count[i+1][j][k];
                }
            }
        }
        for (int j=0; j<10; j++) {
            right_pair_count[i][cur][j] += right_count[j];
        }
        right_count[cur]++;
    }

    long long ans = 0;

    for (int i=2; i<n-2; i++) {
        for (int j=0; j<10; j++) {
            for (int k=0; k<10; k++) {
                ans += (1LL * left_pair_count[i-1][j][k] * right_pair_count[i+1][k][j]) % mod;
                ans %= mod;
            }
        }
    }
    return ans;
}

signed main()
{
    cout << countPalindromes("9999900000") << endl;
}