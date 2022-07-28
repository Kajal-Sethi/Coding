class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sotred str, strings belonging to this gp
        map<string, vector<string>> mp;
        vector<vector<string>> ans;
        int i;
        
        for(i=0; i<strs.size(); i++)
        {
            string use = strs[i];
            sort(use.begin(), use.end());
            mp[use].push_back(strs[i]);
        }
        
        for(pair<string, vector<string>> thiss: mp)
        {
            ans.push_back(thiss.second);
        }
        return ans;
    }
};