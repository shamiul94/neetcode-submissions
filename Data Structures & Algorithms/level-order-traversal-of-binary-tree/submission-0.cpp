
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

typedef vector<vector<int>> vvi; 

class Solution {
public:
    void dfs(TreeNode* root, int h, vvi& res) {
        if(!root) return;

        if(res.size() == h) {
            res.push_back(vector<int>()); 
        }

        res[h].push_back(root->val);

        dfs(root -> left, h+1, res);
        dfs(root -> right, h+1, res);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vvi res; 
        dfs(root, 0, res);
        return res;
    }
};
