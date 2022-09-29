class Solution {
public:
    
    int dp[502][502];
    int summ(vector<int>& arr, int i, int j) 
    {
        if(i==j)
            return arr[i];
        
        int maxx=arr[i];
        for(int p=i+1; p<=j; p++)
            maxx = max(maxx, arr[p]);
        
        return maxx*(j-i+1);
    }
        
    int solve(vector<int>& arr, int k, int i, int j) 
    {
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int cost, maxx = INT_MIN;
        for(int ind = i; ind<min(i+k, j); ind++)
        {
            cost = summ(arr, i, ind) + solve(arr, k, ind+1, j);
            maxx = max(maxx, cost);
            
            // cout<<summ(arr, i, ind)<<" ";
        }
        
        // cout<<maxx<<" "<<i<<" "<<j<<endl;
        return dp[i][j] = maxx;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, k, 0, arr.size());
    }
};