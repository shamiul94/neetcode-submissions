class Solution {
public:
    
    bool isPal(string& s, int lo, int hi) {
        // lo = 3, hi = 5, strLen = 5 - 3 + 1 = 3
        // i = 3; i < 4
        int strLen = hi - lo + 1; // 5-3+1 = 3 => 3/2 = 1

        for(int i = lo; i < lo + (strLen/2); i++) {
            // 5 - 3 + 3
            if(s[i] != s[hi - i + lo]) return false;
        }
        return true;
    }

    void dfs(string& s, int idx, vector<string>& vec, vector<vector<string>>& result) {
        if(idx == s.size()) {
            result.push_back(vec);
            return;
        }

        for(int i = idx; i < s.size(); i++) {
            if(isPal(s, idx, i)) {
                vec.push_back(s.substr(idx, i - idx + 1)); 
                dfs(s, i+1, vec, result);
                vec.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<string> vec; 
        vector<vector<string>> result;
        dfs(s, 0, vec, result);
        return result;
    }
};

class Solution2 {
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