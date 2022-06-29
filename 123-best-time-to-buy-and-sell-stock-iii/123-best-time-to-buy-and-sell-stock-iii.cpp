class Solution {
public:
    
    int t[100001][3][4];
    // return max profit atmost k times
    int solve(vector<int>& arr, int i, int buy, int time)
    {
        if(i>=arr.size() || time==0)
            return t[i][buy+1][time] = 0;
           // return 0;
        
        if(t[i][buy+1][time]!=-1)
            return t[i][buy+1][time];
        
        if(buy==1)
            return t[i][buy+1][time] = max(solve(arr, i+1, buy, time), solve(arr, i+1, -buy, time)+(-buy*arr[i]));
            // return max(solve(arr, i+1, buy, time), solve(arr, i+1, -buy, time)+(-buy*arr[i]));
        
        else
            return t[i][buy+1][time] = max(solve(arr, i+1, buy, time), solve(arr, i+1, -buy, time-1)+(-buy*arr[i]));
            // return max(solve(arr, i+1, buy, time), solve(arr, i+1, -buy, time-1)+(-buy*arr[i]));
    }
    
    int maxProfit(vector<int>& prices) {
        // at most two transactions.
        memset(t, -1, sizeof(t));
        return solve(prices, 0, 1, 2);
    }
};