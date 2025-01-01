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

TreeNode *insert(int l, int r, vector<int> &nums)
{
    if (l > r)
        return NULL;
    int m = (l + r) / 2;
    TreeNode *root = new TreeNode;
    root->val = nums[m];
    root->left = insert(l, m - 1, nums);
    root->right = insert(m + 1, r, nums);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int l = 0;
    int r = int(nums.size()) - 1;
    TreeNode *root = insert(l, r, nums);

    return root;
}
int main()
{
    FastIO;

    return 0;
}