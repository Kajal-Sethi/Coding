class Solution {
public:
    
    int t[51][51][51];
    int solve(int m, int n, int moves, int i, int j)
    {
        if(i<0||i>=m || j<0||j>=n)
            return 1;
        
        if(moves<=0)
            return 0;
        
        if(t[moves][i][j]!=-1)
            return t[moves][i][j];
        
        int row[] = {1,-1,0,0};
        int col[] = {0,0,1,-1};
        int k=0;
        long long total = 0;
        
        while(k<4)
        {    
            // if(t[moves-1][i+row[k]][j+col[k]]==-1)
            //     t[moves-1][i+row[k]][j+col[k]] = solve(m,n,moves-1,i+row[k], j+col[k]);
                
            total+=solve(m,n,moves-1,i+row[k], j+col[k]);
            k++;
        }
        
        return t[moves][i][j] = total%1000000007;
        
    }
        
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(t,-1, sizeof(t));
        return solve(m,n,maxMove,startRow, startColumn);
    }
};