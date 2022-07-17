class Solution {
public:
    bool canChange(string start, string target) {
        // count L, R and _. If number doesnt match return false.
        
        map<int, char>mp;
        int i=0, j=0; 

        while(i<start.size() && j<target.size())
        {
            
            while(start[i]=='_')
                i++;
            
            while(target[j]=='_')
                j++;
            
            if(i==start.size() && j==start.size())
            return true;
            
            // cout<<i<<j<<;
            if(target[j]!=start[i])
                return false;
            
            if(start[i]=='L')
                if(j>i)
                    return false;
            
            if(start[i]=='R')
            {
                // cout<<i<<j;
                if(j<i)
                    return false;
            }
            i++;
            j++;
        }
        
        
        while(start[i]=='_')
            i++;

        while(target[j]=='_')
            j++;

        if(i==start.size() && j==start.size())
            return true;
        
        return false;
    }
};