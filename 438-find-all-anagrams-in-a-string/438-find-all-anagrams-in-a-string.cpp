class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i, start=0, end=0;
        vector<int> ans, count(26,0), use(26,0);
        
        if(s.size()<p.size())
            return ans;
        
        for(i=0; i<p.size(); i++)
            count[p[i]-'a']++;
            
        while(end<s.size())
        {
            use[s[end]-'a']++;
            while(end-start>=p.size())
            {
                use[s[start]-'a']--;
                start++;
            }
            
            if(use==count)
                ans.push_back(start);
            
            end++;    
        }
        
        return ans;
    }
};