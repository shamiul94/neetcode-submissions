class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < strs.size(); i++) {
            string s = strs[i]; 
            sort(s.begin(), s.end());
            mp[s].push_back(strs[i]);
        }

        unordered_map<string, vector<string>>::iterator it;

        vector<vector<string>> anagramLists; 
        for(it = mp.begin(); it != mp.end(); it++) {
            vector<string> anagramList = it->second;
            anagramLists.push_back(anagramList);
        }

        return anagramLists;
    }
};
