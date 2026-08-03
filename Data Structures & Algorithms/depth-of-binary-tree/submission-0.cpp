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
    int dfs(TreeNode* root, int h) {
        if(!root) return h;

        int leftHeight = dfs(root -> left, h+1); 
        int rightHeight = dfs(root -> right, h+1);

        return max(leftHeight, rightHeight);
    }

    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }
};
