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

int minimumKeypresses(string s)
{
    map<char, int> mp;
    for (char & c : s) {
        if (mp.count(c)) mp[c]++;
        else mp[c] = 1;
    }
    vector<pair<int, char>> counts; // frequency, character
    for (auto it = mp.begin(); it!=mp.end(); it++) {
        // -1 because too lazy to figure out how to sort in reverse
        counts.push_back({-1 * it->second, it->first});
    }
    sort(counts.begin(), counts.end());
    int ans = 0;
    for (int i=0; i<counts.size(); i++) {
        if (i <= 8) ans -= counts[i].first;
        else if (i >= 9 && i <= 17) ans -= 2 * counts[i].first;
        else ans -= 3 * counts[i].first;
    }
    return ans;
}

signed main()
{
    cout << minimumKeypresses("aaaaaaaabcdefgggghijkllllllllllmmmnoppponono") << endl;
}