class Solution {
public:
    
    // buy=-1
    // sell=1
    int t[101][1001][3];
    int solve(int k, vector<int>& prices, int index, int turn)
    {
        if(k==0 || index==prices.size())
            return 0; 
        
        if(t[k][index][turn+1]!=-1)
            return t[k][index][turn+1];
        
        if(turn == -1)
            return t[k][index][turn+1] = max(solve(k, prices, index+1, turn), solve(k, prices, index+1, -turn)+turn*prices[index]);
        // dec k at sell
        
        else
            return t[k][index][turn+1] = max(solve(k, prices, index+1, turn), solve(k-1, prices, index+1, -turn)+turn*prices[index]);
    }
        
    int maxProfit(int k, vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(k, prices, 0, -1);
    }
};