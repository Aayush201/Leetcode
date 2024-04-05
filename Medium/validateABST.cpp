/*
Problem Link : https: // leetcode.com/problems/validate-binary-search-tree/description/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // {leftMax,rightMin}
    pair<long, long> solve(TreeNode *root, bool &ans)
    {
        if (!root)
            return {LONG_MIN, LONG_MAX};
        if (!root->left && !root->right)
            return {root->val, root->val};
        pair<long, long> left = solve(root->left, ans);
        pair<long, long> right = solve(root->right, ans);
        if (left.first >= root->val)
            ans = false;
        if (right.second <= root->val)
            ans = false;
        return {max({right.first, 1L * root->val, left.first}), min({right.second, 1L * root->val, left.second})};
    }
    TreeNode *prev = NULL;
    void approach2(TreeNode *root, bool &ans)
    {
        if (!root)
            return;
        approach2(root->left, ans);
        if (prev)
            if (prev->val >= root->val)
                ans = false;
        prev = root;
        if (!ans)
            return;
        approach2(root->right, ans);
    }
    bool isValidBST(TreeNode *root)
    {
        bool ans = true;
        // solve(root,ans);
        approach2(root, ans);
        return ans;
    }
};