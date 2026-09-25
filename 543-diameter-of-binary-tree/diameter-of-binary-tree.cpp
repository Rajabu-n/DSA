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
    int diameter=0;
   int findmax(TreeNode *root)
   {
        if(root==nullptr) return 0;
        int lh=findmax(root->left);
        int rh=findmax(root->right);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);  //used to return the height
   }
    int diameterOfBinaryTree(TreeNode* root) {
      
       findmax(root);
       return diameter;
    }
};