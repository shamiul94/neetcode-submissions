class Solution {
public:
    string S1; 
    string S2; 
    string S3;

    bool solve(int idx1, int idx2, int idx3, vector<vector<int>>& dp) {
        if(idx3 == S3.size()) {
            return true;
        }

        if(idx1 == S1.size() && idx2 == S2.size()) {
            return true;
        }

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(idx1 < S1.size() && idx2 < S2.size() && 
            S3[idx3] == S1[idx1] && S3[idx3] == S2[idx2]) {

            return dp[idx1][idx2] = solve(idx1 + 1, idx2, idx3 + 1, dp) 
                    || solve(idx1, idx2 + 1, idx3 + 1, dp);

        } else if(idx1 < S1.size() && S3[idx3] == S1[idx1]) {
            return dp[idx1][idx2] = solve(idx1 + 1, idx2, idx3 + 1, dp);
        } else if(idx2 < S2.size() && S3[idx3] == S2[idx2]) {
            return dp[idx1][idx2] = solve(idx1, idx2 + 1, idx3 + 1, dp);
        } else {
            return dp[idx1][idx2] = false;
        }
    }

    bool isInterleave(string s1, string s2, string s3) {
        S1 = s1; 
        S2 = s2; 
        S3 = s3;

        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        if(S1.size() + S2.size() != S3.size()) return false; 

        return solve(0, 0, 0, dp);

    }
};


class Solution4 {
public:
    string S1; 
    string S2; 
    string S3;

    /**
        1. we don't really need idx3 from the Solution2, because we guarantee that 
            S1.size + S2.size == S3.size, so idx1 + idx2 == idx3
                - i.e. (0,0,0) -> (0+1,0,0+1) -> (1, 0+1, 1+1) == (1,1,2) -> shows that idx3 == idx1 + idx2
        2. this is exactly why 2D DP works here, 3D DP not needed. 
        3. 
    */

    bool solve(int idx1, int idx2, vector<vector<int>>& dp) {

        int idx3 = idx1 + idx2; 

        /**
            1. this base case is tricky but enough to cover all calid case. 
            2. We have already guaranteed that S1 + S2 == S3, so, when we are at 
                idx3 or idx1 + idx2 == S3.size, that mean idx1 and idx2 will never get to a value
                beyond S1.size or S2.size. 
                    - example, lets say, s1 = 3, s2 = 2, s3 = 5; 
                        - 1 + 4 == 5 -- not possible
                        - 3 + 2 == 5
        */
        if(idx3 == S3.size()) {
            return true;
        }

        if(idx1 == S1.size() && idx2 == S2.size()) {
            return true;
        }

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(S3[idx3] == S1[idx1] && S3[idx3] == S2[idx2]) {
            return dp[idx1][idx2] = solve(idx1 + 1, idx2, dp) 
                    || solve(idx1, idx2 + 1, dp);
        } else if(S3[idx3] == S1[idx1]) {
            return dp[idx1][idx2] = solve(idx1 + 1, idx2, dp);
        } else if(S3[idx3] == S2[idx2]) {
            return dp[idx1][idx2] = solve(idx1, idx2 + 1, dp);
        } else {
            return dp[idx1][idx2] = false;
        }
    }

    bool isInterleave(string s1, string s2, string s3) {
        S1 = s1; 
        S2 = s2; 
        S3 = s3;

        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        if(S1.size() + S2.size() != S3.size()) return false; 

        return solve(0, 0, dp);

    }
};



class Solution2 {
public:
    string S1; 
    string S2; 
    string S3;

    bool solve(int idx1, int idx2, int idx3, vector<vector<int>>& dp) {
        if(idx3 == S3.size()) {
            return true;
        }

        if(idx1 == S1.size() && idx2 == S2.size()) {
            return true;
        }

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(S3[idx3] == S1[idx1] && S3[idx3] == S2[idx2]) {
            return dp[idx1][idx2] = solve(idx1 + 1, idx2, idx3 + 1, dp) 
                    || solve(idx1, idx2 + 1, idx3 + 1, dp);
        } else if(S3[idx3] == S1[idx1]) {
            return dp[idx1][idx2] = solve(idx1 + 1, idx2, idx3 + 1, dp);
        } else if(S3[idx3] == S2[idx2]) {
            return dp[idx1][idx2] = solve(idx1, idx2 + 1, idx3 + 1, dp);
        } else {
            return dp[idx1][idx2] = false;
        }
    }

    bool isInterleave(string s1, string s2, string s3) {
        S1 = s1; 
        S2 = s2; 
        S3 = s3;

        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        if(S1.size() + S2.size() != S3.size()) return false; 

        return solve(0, 0, 0, dp);

    }
};
