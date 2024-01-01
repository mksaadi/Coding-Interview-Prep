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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValid(TreeNode *root, long long minimum, long long maximum)
{
    if (root == nullptr)
        return true;
    if (root->val <= minimum || root->val >= maximum)
    {
        return false;
    }
    return (isValid(root->left, minimum, root->val) && isValid(root->right, root->val, maximum));
}

bool isValidBST(TreeNode *root)
{
    return isValid(root, INT_MIN - 100LL, INT_MAX + 100LL);
}

int main()
{
    FastIO;

    return 0;
}