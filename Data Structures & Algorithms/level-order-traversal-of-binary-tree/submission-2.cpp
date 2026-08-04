
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
typedef vector<int> vi; 


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vvi result; 

        if(!root) return result; 

        queue<TreeNode*> q; 

        int level = 0; 

        q.push(root);

        while(!q.empty()) {
            // if(result.size() == level) {
            //     result.push_back(vi());
            // }

            result.push_back(vi());
            
            int qSize = q.size();
            for(int i = 0; i < qSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                result[level].push_back(node -> val);
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }

            level++;
        }

        return result;
    }
};


class Solution2 {
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
