/*
Problem Link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
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
    void solve(TreeNode *root, int &index, int &k, int &ans)
    {
        if (!root)
            return;
        solve(root->left, index, k, ans);
        k--;
        if (k == 0)
            ans = root->val;
        solve(root->right, index, k, ans);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int ans;
        int index = 1;
        solve(root, index, k, ans);
        return ans;
    }
};