typedef pair<int, int> pii; 
/*
    Why is this O(N)?

    Example: [73, 74, 75, 71, 69, 72]

    Every temperature is:
        1. pushed onto the stack exactly once
        2. popped from the stack at most once

    A temperature can only be popped AFTER it was pushed,
    and once popped, it is gone forever.

    So across ALL iterations:
        pushes <= N
        pops   <= N

    The while loop may run many times in ONE iteration,
    e.g. when 72 arrives:

        stack: 75, 71, 69
                         ↑
        72 pops 69
        72 pops 71

    But those 69 and 71 can never be popped again.

    Therefore, total while-loop iterations across the
    entire algorithm <= N.

    for loop:       N iterations
    total pushes:   N
    total pops:     N
    -------------------
    total work:     O(N)
*/
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
