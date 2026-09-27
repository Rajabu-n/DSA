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
class Solution {
public:
    void findinvert(TreeNode* root)
    {
        if(root==nullptr) return;
        swap(root->left,root->right);
        findinvert(root->left);
        findinvert(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root;
        findinvert(root);
        return root;
    }
};