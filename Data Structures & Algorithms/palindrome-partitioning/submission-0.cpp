class Solution {
public:

    // abcba - 5
    // 01234
    bool isPallindrome(string& s) {
        int strLen = s.size(); 
        for(int i = 0; i <= s.size()/2; i++) { // i < 2
            if(s[i] != s[strLen-1-i]) return false;
        }
        return true;
    }

    // abababababababababababa
    vector<vector<string>> result; 

    void calculate(string& s, string curr, int idx, vector<string>& vec) {
        
        if(idx == s.size()) {
            if(isPallindrome(curr)) {
                vec.push_back(curr);
                result.push_back(vec);
                vec.pop_back();
            }
            return;
        }

        calculate(s, curr + s[idx], idx + 1, vec);
        
        if(curr!= "" && isPallindrome(curr)) {
            vec.push_back(curr); 
            calculate(s, string(1, s[idx]), idx+1, vec);
            vec.pop_back();
        } 

        return;
    }

    vector<vector<string>> partition(string s) {
        vector<string> seed;
        calculate(s, "", 0, seed);
        return result;
    }
};