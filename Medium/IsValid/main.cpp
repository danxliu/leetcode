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

// --------------------Snippet-Ends--------------------------------

bool isValid(string s)
{
    vector<char> st;
    vector<char> prev;
    vector<char> cur;
    for (int i = 0; i < s.size(); i++)
        st.push_back(s[i]);
    if (st.size() < 3)
        return false;
    char l3 = st.back();
    st.pop_back();
    char l2 = st.back();
    st.pop_back();
    char l1 = st.back();
    st.pop_back();
    while (!st.empty())
    {
        if (l1 == 'a' && l2 == 'b' && l3 == 'c')
        {
            for (int i = prev.size() - 1; i >= 0; i--)
            {
                st.push_back(prev[i]);
            }
            if (st.size() < 3)
                return false;
            l3 = st.back();
            st.pop_back();
            l2 = st.back();
            st.pop_back();
            l1 = st.back();
            st.pop_back();
            prev.clear();
            continue;
        }
        prev.push_back(l3);
        l3 = l2;
        l2 = l1;
        l1 = st.back();
        st.pop_back();
    }
    cout << l1 << " " << l2 << " " << l3 << " " << prev.size() << endl;
    return prev.size() == 0 && l1 == 'a' && l2 == 'b' && l3 == 'c';
}

signed main()
{
    cout << isValid("abcabcababcc");
}