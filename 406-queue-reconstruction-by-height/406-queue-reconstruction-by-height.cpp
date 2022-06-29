class Solution {
public:
    
    static bool use(vector<int>r1, vector<int>r2)
    {
        if(r1[0]==r2[0])
            return r1<r2;
        
        return r1>r2;
    }
        
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // sort in dec order for first number and in ascending order for 2nd bumber
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), use);
        int i;
        
        ans.push_back(people[0]);
        
        for(i=1; i<people.size(); i++)
        {
            ans.insert(ans.begin()+people[i][1], people[i]);
        }
        
        return ans;
    }
};