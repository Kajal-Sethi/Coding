class Solution {
public:
//     int solve(vector<int>& prices, int index, int turn, int count)
//     {
//         if(count==1)
//             return prices[index]*turn;
            
// //         if(index==prices.size()-1)
// //             return prices[index]*turn;
        
//         // 1 = buy -1=sell
//         return max(solve(prices, index+1, turn, 0), solve(prices, index+1, -turn) + turn*prices[index]);
//     }
        
    int maxProfit(vector<int>& prices) {
        // return max(0 ,solve(prices, 0, -1, 0));
        
        int i, maxx=0, buy=prices[0];
        for(i=1; i<prices.size(); i++)
        {
            if(prices[i]>buy)
                maxx=max(maxx, prices[i]-buy);
            
            else 
                buy = prices[i];
        }
        return maxx;
    }
};