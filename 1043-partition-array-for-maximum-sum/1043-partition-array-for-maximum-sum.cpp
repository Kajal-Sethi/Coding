class Solution {
public:
    
    int dp[502];
    int summ(vector<int>& arr, int i, int j) 
    {
        if(i==j)
            return arr[i];
        
        int maxx=arr[i];
        for(int p=i+1; p<=j; p++)
            maxx = max(maxx, arr[p]);
        
        return maxx*(j-i+1);
    }
        
    int solve(vector<int>& arr, int k, int i) 
    {
        if(i>=arr.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int cost, maxx = INT_MIN, j = arr.size();
        for(int ind = i; ind<min(i+k, j); ind++)
        {
            cost = summ(arr, i, ind) + solve(arr, k, ind+1);
            maxx = max(maxx, cost);
        }

        return dp[i] = maxx;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, k, 0);
    }
};