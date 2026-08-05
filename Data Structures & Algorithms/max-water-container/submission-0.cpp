class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0; 
        int j = heights.size() - 1; 

        int maxWater = 0; 

        while(i < j) {
            int currArea = (j - i) * min(heights[i], heights[j]);
            maxWater = max(maxWater, currArea); 
            if(heights[i] <= heights[j]) i++; 
            else j--;
        }

        return maxWater;
    }
};
