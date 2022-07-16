class Solution {
public:
    map<char, pair<int,int>> mp;

    int kahatak(int n, vector<int>& startPos, string s, int index)
    {
        pair<int, int> curr = {startPos[0], startPos[1]}, use;
        int i=index, count=0;
        while(i<s.length())
        {
            use = mp[s[i]];
            curr.first += use.first;
            curr.second += use.second;
            
            if(curr.first>=0 && curr.first<n && curr.second>=0 && curr.second<n)
            {
                i++;
                count++;
            }
            
            else 
                return count;
        }
        return count;
    }
        
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        
        mp['U']={-1,0};
        mp['D']={1,0};
        mp['L']={0,-1};
        mp['R']={0,1};
        int i=0;
        vector<int> ans;
        
        for(i=0; i<s.size(); i++)
            ans.push_back(kahatak(n, startPos, s, i));
        
        return ans;
    }
    
};