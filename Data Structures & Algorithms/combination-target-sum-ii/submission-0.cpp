typedef vector<int> vi; 
typedef vector<vector<int>> vvi; 

        /**
            target = 7
            [2,2,3,3]

            States: 
            2f + dfs(2s, ...)
                 2s + dfs(3f, ...)
                      3f + dfs(3s, ...) --> stop
                           3s + _
            3f + dfs(3s)
                 3s + _

        */

class Solution {
public:
    void dfs(vi& cands, int target, int idx, int currSum, vi& path, vvi& result) {

        if(currSum == target) {
            result.push_back(path);
            return;
        }

        if(currSum > target || idx == cands.size()) {
            return; 
        }

        for(int i = idx; i < cands.size(); i++) {
            // skip the duplicate elements as duplicates are chosen as part of subtree
            if(i > idx && cands[i] == cands[i-1]) continue;

            // take the current element in all cases
            path.push_back(cands[i]);
            dfs(cands, target, i+1, currSum + cands[i], path, result);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vi path;
        vvi result;
        dfs(candidates, target, 0, 0, path, result); 
        return result;
    }
};
