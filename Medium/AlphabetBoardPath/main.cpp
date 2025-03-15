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

string alphabetBoardPath(string target) {
    vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
    map<char, pair<int, int>> mp;

    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[i].size(); j++) {
            mp[board[i][j]] = {i, j};
        }
    }

    string ans = "";
    pair<int, int> cur = {0, 0};

    for (int i=0; i<target.size(); i++) {
        pair<int, int> next = mp[target[i]];
        
        if (target[i] == 'z') {
            char c = next.second < cur.second ? 'L' : 'R';
            pair<int, int> d = {min(next.second, cur.second), max(next.second, cur.second)};
            for (int j=d.first; j<d.second; j++) {
                ans += c;
            }

            c = next.first < cur.first ? 'U' : 'D';
            d = {min(next.first, cur.first), max(next.first, cur.first)};
            for (int j=d.first; j<d.second; j++) {
                ans += c;
            }
        }
        else {
            char c = next.first < cur.first ? 'U' : 'D';
            pair<int, int> d = {min(next.first, cur.first), max(next.first, cur.first)};
            for (int j=d.first; j<d.second; j++) {
                ans += c;
            }

            c = next.second < cur.second ? 'L' : 'R';
            d = {min(next.second, cur.second), max(next.second, cur.second)};
            for (int j=d.first; j<d.second; j++) {
                ans += c;
            }
        }

        ans += '!';
        cur = next;
    }
    return ans;
}

signed main()
{

}
