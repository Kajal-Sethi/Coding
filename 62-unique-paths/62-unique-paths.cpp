class Solution {
public:
    
    int t[101][101];
    int path(int i, int j, int m, int n)
    {
        if(i==m-1 && j==n-1)
        {
            t[i][j]=1;
            return t[i][j];
        }
        
        if(i>=m || j>=n)
        {
            t[i][j]=0;
            return t[i][j];
        }
            
        if(t[i][j]!=-1)
            return t[i][j];
        
        t[i][j] = path(i+1, j, m, n) + path(i, j+1, m, n);
        return t[i][j];
    }
        
    int uniquePaths(int m, int n) {
        memset(t, -1, sizeof(t));
        int total=0;
        return path(0, 0, m, n);
        
        // return t[m][n];
    }
};