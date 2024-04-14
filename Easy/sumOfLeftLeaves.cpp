/*
Problem Link : https://leetcode.com/problems/sum-of-left-leaves/description/?envType=daily-question&envId=2024-04-14
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
    void sum(TreeNode *root, int isLeft, int &ans)
    {
        if (!root)
            return;
        if (isLeft && !root->left && !root->right)
        {
            ans += root->val;
            return;
        }
        sum(root->left, 1, ans);
        sum(root->right, 0, ans);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        int ans = 0;
        if (!root || (!root->left && !root->right))
            return ans;
        sum(root->left, 1, ans);
        sum(root->right, 0, ans);
        return ans;
    }
};