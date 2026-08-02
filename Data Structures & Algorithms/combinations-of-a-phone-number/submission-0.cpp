typedef unordered_map<int, string> umis; 
typedef vector<string> vs; 

class Solution {
public:

    void dfs(vs& letters, int lettersIdx, string currStr, vs& res) {
        if(lettersIdx == letters.size()) {
            if(currStr != "") res.push_back(currStr); 
            return; 
        }

        for(int i = 0; i < letters[lettersIdx].size(); i++) {
            char ch = letters[lettersIdx][i];
            currStr.push_back(ch);
            dfs(letters, lettersIdx+1, currStr, res); 
            currStr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        umis maps = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };

        vs charSets; 

        for(int i = 0; i < digits.size(); i++) {
            charSets.push_back(maps[digits[i] - '0']);
        }

        vs res;
        dfs(charSets, 0, "", res);
        return res;
    }
};
