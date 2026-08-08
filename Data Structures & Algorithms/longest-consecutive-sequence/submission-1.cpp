class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int maxLen = 0;

        /*
            1. it's an unconventional solution but it works. backtracking, DP, 
                sliding window, two pointers nothing else really works. 
            2. the working solution looks like a bruteforce one. 
            3. One confusing point is - how is it O(N) although it has while loop inside a for loop? 
            4. The answer is, for seq - 1,2,3,4,5 - the seq can only start from 1 because 
                if(numSet.find(nums[i]-1) != numSet.end()) continue; ---> it enforces that rule. 
                - the loop will be skipped for 2,3,4,5 and will only run from 1. 
            5. as a result, the while loop will only be run once for each sequence, not more than that.
            
            6. Why is this O(N) even though there is a while inside the for?

                Example: [1,2,3,4,5]

                Only 1 can start the sequence because:
                    1 has no predecessor  -> start while
                    2 has predecessor 1  -> skip
                    3 has predecessor 2  -> skip
                    4 has predecessor 3  -> skip
                    5 has predecessor 4  -> skip

                So the while does:
                    1 -> 2 -> 3 -> 4 -> 5     (5 iterations)

                It does NOT do:
                    1 -> 2 -> 3 -> 4 -> 5
                    2 -> 3 -> 4 -> 5
                    3 -> 4 -> 5
                    ...

                because the predecessor check prevents 2,3,4,5 from
                starting another while loop.

                Therefore, across ALL while loops combined, an element
                can only be visited as part of its sequence starting
                from the first element. Total while iterations <= N.

                for loop:                 N
                all while iterations:    <= N
                total:                   <= 2N = O(N)
           

        */

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
