class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, int target, int currSum, int idx, vector<int>& path) {
        if(currSum > target) {
            // invalid
            return;
        }

        if(currSum == target) {
            res.push_back(path);
            return;
        }

        if(idx > nums.size()-1) {
            return;
        }

        // take curr num
        path.push_back(nums[idx]);
        backtrack(nums, target, currSum + nums[idx], idx, path); 
        path.pop_back();

        // not take curr num
        backtrack(nums, target, currSum, idx+1, path);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path; 

        backtrack(nums, target, 0, 0, path);

        return res;
    }
};
