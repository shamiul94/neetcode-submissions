class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; 

        for(const string& s : strs) {
            vector<int> counter(26, 0); // {0, 0, 0, ..., 0} ----> length 26
            for(const char& c: s) {
                counter[c - 'a']++;
            }

            string key = "";
            for(const int count: counter) {
                key += to_string(count) + to_string(count + 'a');
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> result; 

        for(const auto& pair: mp) {
            result.push_back(pair.second);    
        }

        return result; 
    }

    vector<vector<string>> groupAnagrams3(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(const string& s: strs) {
            string key = s; 
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> anagramLists;
        for(const auto& pair: mp) {
            anagramLists.push_back(pair.second);
        }

        return anagramLists;
    }

    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
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
