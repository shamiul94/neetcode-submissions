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


        // p && q > root
        // p < root && q > root
        //  return root
        // p || q == root
        //  return root
 */

class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if any of them is == root, you are already at the LCA
        if(p -> val == root -> val || q -> val == root -> val) {
            return root;
        }

        // p,q are on different sides of root, so no other LCA but root is possible
        if((p -> val < root -> val && q -> val > root -> val) || 
           (q -> val < root -> val && p -> val > root -> val)) {

            return root;
        }

        // at this stage, both p,q are guaranteed to be (> root) or (< root) as its a BST
        if(p -> val > root -> val) {
            return dfs(root -> right, p, q);
        }

        if(p -> val < root -> val) {
            return dfs(root -> left, p, q);
        }

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};
