class Solution {
public:
    
    int dp[1001];
    
    int solve(vector<int>& nums, int target, int sum) {
        
        if(target<sum)
            return 0;
        
        if(target==sum)
            return 1;

        if(dp[sum]!=-1)
            return dp[sum];
        
        int i, count=0;
        for(i=0; i<nums.size(); i++)
        {
            if(sum+nums[i]<=target)
                count+=solve(nums, target, sum+nums[i]);
        
            // count+=solve(nums, target, sum);
        }
        
        return dp[sum] = count;       
    }
    
      
    int combinationSum4(vector<int>& nums, int target) {
        // find unique combination first
        memset(dp,-1,sizeof(dp));
        return solve(nums, target, 0);
        
    }
};