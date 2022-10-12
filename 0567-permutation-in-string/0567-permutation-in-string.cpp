class Solution {
public:
    
    
    bool checkInclusion(string P, string S) {
            // if all char in one is present in other in a contigeous substr then return true
    // p is the pwd. s is encrypted
    if(P.size()>S.size())
        return false;
        
    vector<int> freq(26, 0), sec(26, 0);
    int i, st=0;
    
    for(i=0; i<P.size(); i++)
        freq[P[i]-'a']++;
    
    for(i=0; i<S.size(); i++)
    {
        sec[S[i]-'a']++;
        
        if(i-st+1>=P.size())
        {
            // remove from st and compare with freq
            while(i-st+1>P.size())
            {
                sec[S[st]-'a']--;                
                st++;
            }
            
            if(sec==freq)
                return true;
        }
        
    }
    return false;
    }
};