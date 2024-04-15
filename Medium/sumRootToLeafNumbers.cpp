/*
Problem Link : https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=daily-question&envId=2024-04-15
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
    void solve(TreeNode *root, int &sum, int val)
    {
        if (!root)
            return;
        val *= 10;
        val += root->val;
        if (!root->left && !root->right)
        {
            sum += val;
            return;
        }
        solve(root->left, sum, val);
        solve(root->right, sum, val);
    }
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        solve(root, sum, 0);
        return sum;
    }
};