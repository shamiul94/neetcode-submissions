class Solution {
public:
    /*
    abcd wxyz

    axbwcydz



    abcd pqrstuvwxyz


    a pq b rs c t d uvxxyz
    */

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
