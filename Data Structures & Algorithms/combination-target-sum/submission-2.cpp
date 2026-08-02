typedef vector<int> vi; 
typedef vector<vector<int>> vvi; 

/*
For loop
|
+-- 2 (choose nums[0])
|   |
|   +-- 2 (choose nums[0] again)
|   |   |
|   |   +-- 2
|   |   |   |
|   |   |   +-- 2 ... stop (sum > target)
|   |   |
|   |   +-- 3
|   |       |
|   |       +-- 3 ... stop
|   |
|   +-- 3 (choose nums[1])
|       |
|       +-- 3
|           |
|           +-- 3 ... stop
|
+-- 3 (choose nums[1])
    |
    +-- 3
        |
        +-- 3 ... stop

*/

class Solution {
public:
    void dfs(vi& nums, int target, int idx, int currSum, vi& path, vvi& result) {
        if(currSum == target) {
            result.push_back(path);
            return;
        }

        if(idx == nums.size() || currSum > target) {
            return;
        }

        for(int i = idx; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, target, i, currSum+nums[i], path, result);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vvi res;
        vi path;
        dfs(nums, target, 0, 0, path, res);
        return res;
    }
};


class Solution2 {
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
