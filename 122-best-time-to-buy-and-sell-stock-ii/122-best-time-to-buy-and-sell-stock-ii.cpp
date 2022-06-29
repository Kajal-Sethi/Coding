class Solution {
public:
    // returns maximum profit
    int t[30001][3];
    
    int solve(int index, vector<int>& prices, int buy)
    {
        if(index>=prices.size())
            return 0;
        
        if(t[index][buy+1]!=-1)
            return t[index][buy+1];
        
        return t[index][buy+1] = max(solve(index+1, prices, buy), solve(index+1, prices, -buy) + (-buy*prices[index]));
        
//         if(buy==-1)
//             return max(solve(index+1, prices, buy), solve(index+1, prices, -buy)+prices[index]);
        
//         else
//             return max(solve(index+1, prices, buy), solve(index+1, prices, -buy)-prices[index]);
    }
        
    int maxProfit(vector<int>& prices) {
        // we can buy and sell the stock any number of times
        memset(t,-1,sizeof(t));
        return solve(0, prices, 1);
        
    }
};