class Solution {
public:
    
    
    bool checkInclusion(string P, string S) {
            // if all char in one is present in other in a contigeous substr then return true
    // p is the pwd. s is encrypted
    if(P.size()>S.size())
        return false;
        
    // cout<<P;
    vector<int> freq(26, 0), sec(26, 0);
    int i, count=0, finder=0;
    
    for(i=0; i<P.size(); i++)
    {
        if(freq[P[i]-'a']==0)
            count++;
        
        freq[P[i]-'a']++;
    }
    
    int st=0;
    for(i=0; i<S.size(); i++)
    {
        if(sec[S[i]-'a']==0)
            finder++;
        
        sec[S[i]-'a']++;
        
        if(finder>=count)
        {
            // remove from st and compare with freq
            while(i-st+1>P.size())
            {
                sec[S[st]-'a']--;
                if(sec[S[st]-'a']==0)
                    finder--;
                
                st++;
            }
            
            // if(i-st+1==P.size())
            //     cout<<S.substr(st, P.size())<<endl;
            if(sec==freq)
                return true;
        }
        
    }
    return false;
    }
};