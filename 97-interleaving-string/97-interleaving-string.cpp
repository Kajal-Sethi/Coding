class Solution {
public:
    
    map<string, bool> mp;
    bool solve(string s1, string s2, string s3) {
        
        if(s3.size()<=0 && s1.size()<=0 && s2.size()<=0)
            return true;
        
        string s=s1;
        s.push_back(' ');
        s= s + s2;
        s.push_back(' ');
        s= s + s3;
        s.push_back(' ');
        
        if(mp.find(s)!=mp.end())
            return mp[s];
        
        if(s1.size()>0 && s2.size()>0 && s3[s3.size()-1]==s1[s1.size()-1] && s3[s3.size()-1]==s2[s2.size()-1])
            return mp[s] = solve(s1.substr(0, s1.size()-1),s2,s3.substr(0, s3.size()-1)) || solve(s1,s2.substr(0, s2.size()-1),s3.substr(0, s3.size()-1));
        
        if(s1.size()>0 && s3[s3.size()-1]==s1[s1.size()-1])
            return mp[s]= solve(s1.substr(0, s1.size()-1),s2,s3.substr(0, s3.size()-1));
        
        if(s2.size()>0 && s3[s3.size()-1]==s2[s2.size()-1])
            return mp[s]= solve(s1,s2.substr(0, s2.size()-1),s3.substr(0, s3.size()-1));
        
        else // if(s3[s3.size()-1]!=s1[s1.size()-1] && s3[s3.size()-1]!=s2[s2.size()-1])
            return mp[s] = false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!=s1.size()+s2.size())
            return false;
        
        return solve(s1,s2,s3);
    }
};