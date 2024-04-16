/*
Problem Link : https://leetcode.com/problems/add-one-row-to-tree/description/?envType=daily-question&envId=2024-04-16
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
    void solve(TreeNode *root, int val, int depth, int curDepth)
    {
        if (!root)
            return;
        if (curDepth >= depth)
            return;
        if ((curDepth + 1) == depth)
        {
            TreeNode *left = root->left;
            TreeNode *right = root->right;
            TreeNode *newNode1 = new TreeNode(val, left, NULL);
            TreeNode *newNode2 = new TreeNode(val, NULL, right);
            root->left = newNode1;
            root->right = newNode2;
            return;
        }
        solve(root->left, val, depth, curDepth + 1);
        solve(root->right, val, depth, curDepth + 1);
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newNode = new TreeNode(val, root, NULL);
            return newNode;
        }
        solve(root, val, depth, 1);
        return root;
    }
};