class Solution {
public:
    int dp[302][302];
    int solve(vector<int>& nums, int i, int j)
    {
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ind, maxx=INT_MIN;
        
        for(ind=i; ind<=j; ind++)
        {
            int cost = nums[i-1]*nums[ind]*nums[j+1] + solve(nums, i, ind-1) + solve(nums, ind+1, j);
            
            maxx = max(maxx, cost);
        }
        
        return dp[i][j] = maxx;
    }
        
    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size();
        memset(dp,-1, sizeof(dp));
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        // for(int ind=0; ind<nums.size(); ind++)
        //     cout<<nums[ind]<<" ";
        
        return solve(nums, 1, n);
    }
};