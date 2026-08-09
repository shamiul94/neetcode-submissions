typedef pair<int, int> pii; 

class Solution {
public:
    int solve(vector<int>& nums, int idx, int remain, 
                unordered_map<int, unordered_map<int, int>>& dp) {

        if(idx == nums.size() && remain == 0) return 1;
        if(idx == nums.size()) return 0;
        
        if(dp.contains(idx) && dp[idx].contains(remain)) return dp[idx][remain];

        int add = solve(nums, idx + 1, remain + nums[idx], dp);
        int subtract = solve(nums, idx + 1, remain - nums[idx], dp);

        return dp[idx][remain] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // idx vs <remSum, waysCount>
        unordered_map<int, unordered_map<int, int>> dp;
        return solve(nums, 0, target, dp);
    }
};
