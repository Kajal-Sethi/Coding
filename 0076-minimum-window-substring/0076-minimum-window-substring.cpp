class Solution {
public:
    string minWindow(string str, string t) {
        vector<int> freq(256,0), check(256, 0);
        int end=0, st=0, ans=INT_MAX, c1=0, c2=0, fstart=0;
        
        if(str.size()<t.size())
            return "";
        
        for(auto s:t)
        { 
            // cout<<s-'a';
            if(freq[s]==0)
                c1++;
        
            freq[s]++;
        }
        
        while(end<str.size())
        {
            check[str[end]]++;
            
            if(check[str[end]]==freq[str[end]])
                c2++;
        
            while(c1<=c2 && st<end)
            {
                check[str[st]]--;
                if(check[str[st]]<freq[str[st]])
                {
                    check[str[st]]++;
                    break;
                }
                
                st++;
            }
            
            if(c1==c2 && ans>(end-st+1))
            {
                ans=end-st+1;
                fstart=st;
            }
            
            end++;
        }
        
        if(ans>str.size())
            return "";
        
        return str.substr(fstart, ans); 
    }
};