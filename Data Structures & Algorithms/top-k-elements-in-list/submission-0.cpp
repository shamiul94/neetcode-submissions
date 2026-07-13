typedef pair<int, int> pii; 


class Compare {
public: 
    bool operator()(pii &pair1, pii &pair2) {
        return pair1.second < pair2.second;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCountMap; 
        priority_queue<pii, vector<pii>, Compare> pq;

        for(int i = 0; i < nums.size(); i++) {
            // number already exists in Map
            // if(numCountMap.find(nums[i]) != numCountMap.end()) {
            //     numCountMap
            // }

            // automatically creates if not exists and increases by 1
            numCountMap[nums[i]]++;
        }

        unordered_map<int, int>::iterator it;

        for(it = numCountMap.begin(); it != numCountMap.end(); it++) {
            int key = it->first; 
            int value = it -> second;

            pq.push({key, value});
        }

        int n = 0; 
        vector<int> result; 

        while(n < k) {
            n++; 
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};
