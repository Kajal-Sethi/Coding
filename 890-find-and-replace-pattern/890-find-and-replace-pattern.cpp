class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, char> mp;
        set<char> ss;
        int i, j, k;
        vector<string> ans;
        
        for(i=0; i<words.size(); i++)
        {
            if(words[i].size()!=pattern.size())
                continue;
            
            ss.clear();
            mp.clear();
            j=0;
            int flag=0;
            while(j<words[i].size())
            {
                if(ss.find(words[i][j])==ss.end() && mp.find(pattern[j])==mp.end())
                {
                    ss.insert(words[i][j]);
                    mp[pattern[j]] = words[i][j];
                }
                
                if(words[i][j]!=mp[pattern[j]])
                {
                    flag=1;
                    break;
                }
                j++;
            }
            if(flag==0)
                ans.push_back(words[i]);
        }
            
        return ans;
    }
};