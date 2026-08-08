typedef pair<int, int> pii; 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pii> stk; 

        vector<int> result(temperatures.size(), 0); 

        for(int i = 0; i < temperatures.size(); i++) {
            int curr = temperatures[i];
            
            while(!stk.empty() && curr > stk.top().first) {
                result[stk.top().second] = i - stk.top().second;
                stk.pop();
            }

            stk.push({temperatures[i], i});
        }

        return result;      
    }
};
