class Solution {
public:
    
    int t[10001][8][8];
    int solve(int throws, int prev, int prev2)
    {        
        if(throws==0)
            return t[throws][prev][prev2] = 1;
        
        if(t[throws][prev][prev2] != -1)
            return t[throws][prev][prev2];
        
        int p=0, q=0, r=0, s=0, xx=0, u=0;
        long long sum=0;

        
        for(int i=1; i<=6; i++)
        {
            if(i==prev || i==prev2)
                continue;
            
            else if(i==1)
            {
                if(t[throws-1][i][prev] == -1)
                    t[throws-1][i][prev] = solve(throws-1, i, prev);
                
                p= t[throws-1][i][prev];
            }
            
            else if(i==2 && prev!=4 && prev!=6)
            {
                if(t[throws-1][i][prev] == -1)
                    t[throws-1][i][prev] = solve(throws-1, i, prev);
                
                q= t[throws-1][i][prev];
            }
            
            else if(i==3 && prev!=6)
            {
                if(t[throws-1][i][prev] == -1)
                    t[throws-1][i][prev] = solve(throws-1, i, prev);
                
                r= t[throws-1][i][prev];
            }
            
            else if(i==4 && prev!=2 && prev!=6)
            {
                if(t[throws-1][i][prev] == -1)
                    t[throws-1][i][prev] = solve(throws-1, i, prev);
                
                s= t[throws-1][i][prev];
            }
            
            else if(i==5)
            {
                if(t[throws-1][i][prev] == -1)
                    t[throws-1][i][prev] = solve(throws-1, i, prev);
                
                xx= t[throws-1][i][prev];
            }
            
            else if(i==6 && prev!=3 && prev!=2 && prev!=4)
            {
                if(t[throws-1][i][prev] == -1)
                    t[throws-1][i][prev] = solve(throws-1, i, prev);
                
                u= t[throws-1][i][prev];
            }
            
            else 
                continue;
        }

        sum = double(q)+p+r+s+xx+u;
        return t[throws][prev][prev2] = sum%1000000007;
    }
        
    int distinctSequences(int n) {
        memset(t, -1, sizeof(t));
        return solve(n, 7, 7);
    }
};