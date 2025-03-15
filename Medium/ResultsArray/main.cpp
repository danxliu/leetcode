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

vector<int> resultsArray(vector<int> &nums, int k)
{
    // Pointer to end of window
    int r = k-1;
    // Number of sorted ending elements
    int e = 1;
    vector<int> ans;
    for (int i=0; i<r; i++) {
        if (nums[i]+1 != nums[i+1]) e = 1;
        else e++;
    }
    
    if (e == k) ans.push_back(nums[r]);
    else ans.push_back(-1);
    
    while (r+1 < nums.size()) {
        // Update number of ending
        if (nums[r+1] == nums[r] + 1) e = min(e + 1, k);
        else e = 1;

        // Update ans
        if (e == k) ans.push_back(nums[r+1]);
        else ans.push_back(-1);
        r++;
    }
    return ans;
}

signed main()
{
    vector<int> nums = {2,2,2,2,2};
    vector<int> ans = resultsArray(nums, 4);
    for (int &i : ans) cout << i << " ";
    cout << endl;
}