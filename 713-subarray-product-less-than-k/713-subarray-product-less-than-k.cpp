class Solution {
public:
    
    map<pair<int, int>, int> mp;
    int solve(vector<int>& nums, int k, int index, int product)
    {
        if(index>=nums.size())
        {
            if(product<k)                
                return 1;
            
            return 0;
        }
         
        if(mp.find({index, product})!=mp.end())
            return mp[{index, product}];
        
        if(product==INT_MAX)
        {
            if(nums[index]<k)                
                return mp[{index, product}] = solve(nums, k, index+1, product)+solve(nums, k, index+1, nums[index]);
            
            else
                return mp[{index, product}] = solve(nums, k, index+1, product);
        }
        
        if(product*nums[index]<k)
            return mp[{index, product}] = 1 + solve(nums, k, index+1, product*nums[index]);
            
        else
            return mp[{index, product}] = 1;
    }
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        return solve(nums, k, 0, INT_MAX);
    }
};