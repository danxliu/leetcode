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

struct robot {
    int position;
    int health;
    int initial;
    char direction;
};

bool compare(robot &a, robot &b) {
    return a.position < b.position;
}

vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
{

    vector<robot> sortedRobots;

    vector<pair<int, int>> survivingHealths;

    int i = 0;
    int numRobots = positions.size();
    
    for (int j=0; j<numRobots; j++) {
        sortedRobots.push_back({positions[j], healths[j], j, directions[j]});
    }

    sort(sortedRobots.begin(), sortedRobots.end(), compare);

    deque<int> rightRobots;
    while (i < numRobots)
    {
        // Robots that will just move to the left
        while (i < numRobots && sortedRobots[i].direction == 'L')
        {
            if (rightRobots.empty())
            {
                survivingHealths.push_back({sortedRobots[i].initial, sortedRobots[i].health});
            }
            else {
                while (!rightRobots.empty() && sortedRobots[i].health > 0) {
                    int cur = rightRobots.front();
                    if (sortedRobots[cur].health < sortedRobots[i].health) {
                        sortedRobots[cur].health = 0;
                        sortedRobots[i].health -= 1;
                        rightRobots.pop_front();
                    }
                    else if (sortedRobots[cur].health > sortedRobots[i].health) {
                        sortedRobots[cur].health -= 1;
                        sortedRobots[i].health = 0;
                    } else {
                        sortedRobots[cur].health = 0;
                        sortedRobots[i].health = 0;
                        rightRobots.pop_front();
                    }
                }

                if (sortedRobots[i].health > 0) {
                    survivingHealths.push_back({sortedRobots[i].initial, sortedRobots[i].health});
                }
            }
            i++;
        }

        while (i < numRobots && sortedRobots[i].direction == 'R')
        {
            rightRobots.push_front(i);
            i++;
        }
    }

    while (!rightRobots.empty()) {
        int j = rightRobots.back();
        survivingHealths.push_back({sortedRobots[j].initial, sortedRobots[j].health});
        rightRobots.pop_back();
    }

    sort(survivingHealths.begin(), survivingHealths.end());
    vector<int> res;
    for (pair<int, int> j : survivingHealths) {
        res.push_back(j.second);
    }

    return res;
}

signed main()
{
    vector<int> positions = {1,2,5,6};
    vector<int> healths = {10,10,11,11};
    string directions = "RLRL";

    vector<int> survivingHealths = survivedRobotsHealths(positions, healths, directions);
    for (int &i : survivingHealths) {
        cout << i << " ";
    }
    cout << endl;
}
