class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i, maxx=nums[0], ans=nums[0];
        
        for(i=1; i<nums.size(); i++)
        {
            if(ans<nums[i] && ans<0)
                ans = nums[i];
            
            else
                ans+=nums[i];
            
            maxx = max(maxx, ans);
        }
        return maxx;
    }
};