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

vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    int n = recipes.size();
    map<string, vector<string>> adjmat;
    map<string, int> indegree;
    unordered_set<string> cs;
    for (string &s : supplies) cs.insert(s);

    for (int i=0; i<n; i++) {
        for (int j=0; j<ingredients[i].size(); j++) {
            if (cs.count(ingredients[i][j])) continue;
            indegree[recipes[i]]++;
            adjmat[ingredients[i][j]].push_back(recipes[i]);
        }
    }

    queue<string> q;
    for (int i=0; i<n; i++) {
        if (indegree[recipes[i]] == 0){
            q.push(recipes[i]);
        }
    }

    vector<string> ans;

    while (!q.empty()) {
        string cur = q.front();
        ans.push_back(cur);
        q.pop();
        for (int i=0; i<adjmat[cur].size(); i++) {
            indegree[adjmat[cur][i]]--;
            if (indegree[adjmat[cur][i]] == 0) {
                q.push(adjmat[cur][i]);
            }
        }
    }
    return ans;
}

signed main()
{

}