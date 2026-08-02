typedef vector<int> vi; 
typedef vector<vector<int>> vvi; 

class Solution {
public:
    void dfs(vi& nums, int idx, vi& currSet, vvi& result) {
        
        result.push_back(currSet); 

        for(int i = idx; i < nums.size(); i++) {
            // skip duplicates
            if(i > idx && nums[i] == nums[i-1]) continue; 

            currSet.push_back(nums[i]); 
            dfs(nums, i+1, currSet, result); 
            currSet.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vi curr; 
        vvi res; 
        dfs(nums, 0, curr, res);
        return res;
    }
};
