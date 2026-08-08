class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int maxLen = 0;

        for(int i = 0; i < nums.size(); i++) {
            // immediate previous number exists == a sequence can NOT start from current number
            if(numSet.find(nums[i]-1) != numSet.end()) {
                continue;
            }

            int currSeqLen = 0;
            int currNum = nums[i];
            // a sequence can start from current number
            while(numSet.find(currNum) != numSet.end()) {
                // currNum is found in set
                currSeqLen++;
                currNum++;
            }

            maxLen = max(maxLen, currSeqLen);
        }

        return maxLen;
    }
};
