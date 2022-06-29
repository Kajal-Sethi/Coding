class Solution {
public:
    
    int t[1001][101][2];
    int solve(int times, vector<int>& arr, int i, int buy)
    {
        if(times==0 || i>=arr.size())
            return t[i][times][buy] = 0;
        
        if(t[i][times][buy]!=-1)
            return t[i][times][buy];
        
        // can buy
        if(buy==1)
            return t[i][times][buy] = max(solve(times, arr, i+1, buy), solve(times, arr, i+1, !buy)-arr[i]);
        
        else 
            return t[i][times][buy] = max(solve(times, arr, i+1, buy), solve(times-1, arr, i+1, !buy)+arr[i]);
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(t, -1, sizeof(t));
        return solve(k, prices, 0, 1);
    }
};