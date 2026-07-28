class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products(nums.size(), 1);

        int prevProduct = 1; 

        for(int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            products[i] *= prevProduct; 
            prevProduct *= curr;    
        }

        int nextProduct = 1; 
        for(int i = nums.size() - 1; i >= 0; i--) {
            int curr = nums[i]; 
            products[i] *= nextProduct;
            nextProduct *= curr;
        }
        
        return products;
    }
};
