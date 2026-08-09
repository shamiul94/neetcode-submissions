class Solution {
public:
    /*
        sum(N) + sum(A) - sum(B) == sum(N)
        => {sum(N) - sum(B)} + sum(A) == sum(N)
        => sum(A) + sum(A) == sum(N)
        => 2 * sum(A) == sum(N)
        => sum(A) == sum(N)/2
    */

    bool solve(vector<int>& nums, int target, int idx, vector<vector<int>>& dp) {
        
        if(idx == nums.size() && target == 0) {
            return true;
        }

        if(idx == nums.size()) return false;

        if(target < 0) return false;
        if(target == 0) return dp[idx][target] = 1;

        if(dp[idx][target] != -1) return dp[idx][target]; 

        // take
        bool take = solve(nums, target - nums[idx], idx + 1, dp);

        // skip
        bool notTake = solve(nums, target, idx + 1, dp);

        return dp[idx][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0; 
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        // odd
        if(sum % 2 != 0) {
            return false;
        }

        int target = sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return solve(nums, target, 0, dp);
    }
};