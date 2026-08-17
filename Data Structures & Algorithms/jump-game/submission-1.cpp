class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 3 0 0  0    0 0 0 0 0 0 0 2 5 7 9 8
        // i     max 
        // not possible to go any further than index 3
        // 
        /*
            1. I could never come up with this solution.
            2. Idea is quite simple. Go through this video of mine - https://photos.app.goo.gl/YgUiBskwiRUEXaT88"
        */

        int maxReach = 0; 

        for(int i = 0; i < nums.size(); i++) {
            if(i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};


class Solution2 {
public:
    bool solve(vector<int>& nums, int idx, vector<int>& dp) {

        if(idx >= nums.size()) {
            return false;
        }

        if(idx == nums.size() - 1) {
            return true;
        }

        if(dp[idx] != -1) return dp[idx];
        
        bool res = false;
        for(int i = 1; i <= nums[idx]; i++) {
            res = res || solve(nums, idx + i, dp);
        }

        return dp[idx] = res;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};
