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

vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
{
    vector<vector<int>> best(2, vector<int>(n, -1));
    vector<vector<int>> adjBlue(n, vector<int>());
    vector<vector<int>> adjRed(n, vector<int>());

    best[0][0] = 0;
    best[1][0] = 0;

    for (int i = 0; i < redEdges.size(); i++)
    {
        adjRed[redEdges[i][0]].push_back(redEdges[i][1]);
    }
    for (int i = 0; i < blueEdges.size(); i++)
    {
        adjBlue[blueEdges[i][0]].push_back(blueEdges[i][1]);
    }

    queue<pair<bool, pair<int, int>>> q;
    q.push({false, {0, 0}});
    q.push({true, {0, 0}});

    while (!q.empty())
    {
        bool prevEdge = q.front().first;
        int curNode = q.front().second.first;
        int curDist = q.front().second.second;
        q.pop();

        if (prevEdge)
        {
            for (int i = 0; i < adjRed[curNode].size(); i++)
            {
                int nextNode = adjRed[curNode][i];
                int nextDist = curDist + 1;
                if (best[!prevEdge][nextNode] == -1 || best[!prevEdge][nextNode] > nextDist)
                {
                    best[!prevEdge][nextNode] = nextDist;
                    q.push({!prevEdge, {nextNode, nextDist}});
                }
            }
        }
        else
        {
            for (int i = 0; i < adjBlue[curNode].size(); i++)
            {
                int nextNode = adjBlue[curNode][i];
                int nextDist = curDist + 1;
                if (best[!prevEdge][nextNode] == -1 || best[!prevEdge][nextNode] > nextDist)
                {
                    best[!prevEdge][nextNode] = nextDist;
                    q.push({!prevEdge, {nextNode, nextDist}});
                }
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (best[0][i] == -1)
        {
            ans.push_back(best[1][i]);
        }
        else if (best[1][i] == -1)
        {
            ans.push_back(best[0][i]);
        }
        else
        {
            ans.push_back(min(best[0][i], best[1][i]));
        }
    }
    return ans;
}

signed main()
{
    vector<vector<int>> redEdges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    vector<vector<int>> blueEdges = {{1, 2}, {2, 3}, {3, 1}};
    vector<int> ans = shortestAlternatingPaths(5, redEdges, blueEdges);
    for (int &i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}