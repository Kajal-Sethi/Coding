class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // count the max occurances of every alphabet for all words
        vector<int> forb(26,0);
        int i, j;
        vector<string> ans;
        
        for(i=0; i<words2.size(); i++)
        {
            vector<int> count(26,0);
            for(j=0; j<words2[i].size(); j++)
                count[words2[i][j]-'a']++;
            
            for(j=0; j<26; j++)
                forb[j] = max(forb[j], count[j]);                
        }
        
        for(i=0; i<words1.size(); i++)
        {
            vector<int> total(26,0);
            for(j=0; j<words1[i].size(); j++)
                total[words1[i][j]-'a']++;
            
            for(j=0; j<26; j++)
                if(total[j]<forb[j])
                    break;
            
            if(j==26)
                ans.push_back(words1[i]);
        }
        
        return ans;
    }
};