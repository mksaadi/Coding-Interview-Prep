// https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *cur = q.front();
            level.push_back(cur->val);
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        ans.push_back(level);
    }

    return ans;
}
int main()
{
    FastIO;
    
    return 0;
}