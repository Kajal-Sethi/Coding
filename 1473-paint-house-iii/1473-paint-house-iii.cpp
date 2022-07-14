class Solution {
public:
    // int minn;
    
    // index, prev, target
    int t[101][21][101];
    int solve(vector<int>& houses, vector<vector<int>>& cost, int index, int target, int prev)
    {
        if(target<0)
            return INT_MAX;
        
        if(target==0 && index>=houses.size())
            return 0;
        
        if(index>=houses.size())
            return INT_MAX;
        
        if(t[index][prev][target]!=-1)
            return t[index][prev][target];
        
        if(houses[index]!=0)
        {    
            if(houses[index]==prev)
                return t[index][prev][target] = solve(houses, cost, index+1, target, prev);
            
            else
                return t[index][prev][target] = solve(houses, cost, index+1, target-1, houses[index]);
        }
        
        else
        {
            int minn=INT_MAX,tans, check; 
            for(int i=0; i<cost[0].size(); i++)
            {
                if(i+1!=prev && target-1>=0)
                {
                    if(t[index+1][i+1][target-1]==-1)
                        t[index+1][i+1][target-1] = solve(houses, cost, index+1, target-1, i+1);
                    
                    if(t[index+1][i+1][target-1]==INT_MAX)
                        continue;
                    
                    tans = t[index+1][i+1][target-1]  + cost[index][i];
                }
                
                
                else if(i+1==prev)
                {
                    if(t[index+1][prev][target]==-1)
                        t[index+1][prev][target] = solve(houses, cost, index+1, target, prev);
                    
                    if(t[index+1][prev][target]==INT_MAX)
                        continue;
                    
                    tans = t[index+1][prev][target]  + cost[index][i];
                }
                
                else 
                    continue;
                    
                minn = min(minn, tans);
            }
            
            return t[index][prev][target] = minn;
        }
        
    }
        
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int minn=INT_MAX;
        
        memset(t, -1, sizeof(t));
        
        minn = solve(houses, cost, 0, target, 0);
        if(minn==INT_MAX)
            return -1;
        
        return minn;
    }
};