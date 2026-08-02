typedef vector<vector<int>> vvi; 
typedef vector<int> vi; 

class Solution {
public:
    void dfs(vi& nums, vi& permutation, vi& dp, vvi& res) {
        if(permutation.size() == nums.size()) {
            res.push_back(permutation); 
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(dp[i] == 1) continue;

            permutation.push_back(nums[i]);
            dp[i] = 1;
            dfs(nums, permutation, dp, res); 
            dp[i] = -1;
            permutation.pop_back();
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vi perm; 
        vi dp(nums.size(), -1); 
        vvi res;

        dfs(nums, perm, dp, res); 
        return res;
    }
};
