class Solution {
public:
   
    // mcm
    int t[301][301];
    bool solve(string s, map<string, int> mp, int i, int j)
    {
        if(i>j)
            return false;
        
        // vector<string>::iterator it;
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        if(mp.find(s.substr(i, j-i+1)) != mp.end())
            return t[i][j] = true;
        
//         it = find(wordDict.begin(), wordDict.end(), s.substr(i, j-i+1));
       
//         if(it!=wordDict.end())
//         {
//             return true;
//         }
        
        int k;
        for(k=i; k<j; k++)
        {
            if(t[i][k]==-1)
                bool left = solve(s, mp,i, k);
            
            if(t[k+1][j]==-1)
                bool right = solve(s, mp,k+1, j);
            
            if(t[i][k] && t[k+1][j])
                return t[i][j] = true;
        }
        
        return t[i][j]=false;
    }
        
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, int> mp;
        memset(t, -1, sizeof(t));
        
        for(int i=0; i<wordDict.size(); i++)
            mp[wordDict[i]]++;
        
        return solve(s, mp,0, s.length());
    }
};