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
    int maxDia = 0; 

    int dfs(TreeNode* root) {
        if(!root) {
            return 0; 
        }

        int leftLen = dfs(root -> left); 
        int rightLen = dfs(root -> right);
        int height = 1 + max(leftLen, rightLen); 

        maxDia = max(maxDia, leftLen + rightLen);
        return height; 
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root); 
        return maxDia;
    }
};
