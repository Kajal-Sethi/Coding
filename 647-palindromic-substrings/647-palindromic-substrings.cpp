class Solution {
public:
    
    int t[1001][1001];
 
    bool ispal(string &s, int i, int j)
    {
        for(; i<j; i++,j--)
            if(s[i]!=s[j])
                return false;

        return true;
    }

    int solve(string s, int i, int j)
    {
        if(j-i<0)
            return 0;
        
        if(j-i==0)
            return 1;

        if(t[i][j]!=-1)
            return t[i][j];
        
        if(t[i][j-1]==-1)
            t[i][j-1] =  solve(s, i, j-1);
        
        if(t[i+1][j]==-1)
            t[i+1][j] = solve(s, i+1, j);
        
        if(t[i+1][j-1]==-1)
            t[i+1][j-1] = solve(s, i+1, j-1);
        
        if(ispal(s, i, j))
            return t[i][j] = 1 + t[i][j-1] + t[i+1][j] - t[i+1][j-1];
        
        else //if(s.size()==3)
            return t[i][j] = t[i][j-1] + t[i+1][j] - t[i+1][j-1];
    }

    int countSubstrings(string s) {
        memset(t, -1, sizeof(t));
        return solve(s, 0, s.size()-1);
    }
};