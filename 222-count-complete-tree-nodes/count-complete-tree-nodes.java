/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public static int getleftHeight(TreeNode root)
    {
        int height=0;
        while(root!=null)
        {
            height++;
            root=root.left;
        }
        return height;
    }
    public static int getrightHeight(TreeNode root)
    {
        int height=0;
        while(root!=null)
        {
            height++;
            root=root.right;
        }
        return height;
    }
    public int countNodes(TreeNode root) {
       int lh=getleftHeight(root);
       int rh=getrightHeight(root);
       if(lh==rh) return (1<<(lh))-1;

       else return 1+countNodes(root.left)+ countNodes(root.right);
    }
}