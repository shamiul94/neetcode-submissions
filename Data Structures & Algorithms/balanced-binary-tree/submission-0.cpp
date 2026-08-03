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
    bool isBalance = true; 

    int dfs(TreeNode* root) {
        if(!root) return 0; 

        int leftHeight = dfs(root -> left);
        int rightHeight = dfs(root -> right);
        int currHeight = 1 + max(leftHeight, rightHeight);
        
        isBalance = isBalance && (abs(rightHeight - leftHeight) <= 1);

        // cout << root -> val << ":" << leftHeight <<  "," << rightHeight << "," << currHeight

        return currHeight;
    }

    bool isBalanced(TreeNode* root) {
        dfs(root);
        return isBalance;
    }
};
