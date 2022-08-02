class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i, j, beg=intervals[0][0], end = intervals[0][1];
        vector<vector<int>> ans;
        
        for(i=1; i<intervals.size(); i++)
        {
            if(end>=intervals[i][0])
            {
                if(end>intervals[i][1])
                    continue;
                
                else
                    end = intervals[i][1];
            }
                
            else
            {
                // add beg and end and update
                ans.push_back({beg, end});
                beg = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        ans.push_back({beg, end});
        return ans;
    }
};