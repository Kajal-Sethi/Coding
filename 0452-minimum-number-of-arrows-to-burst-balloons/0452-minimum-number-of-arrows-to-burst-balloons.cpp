class Solution {
public:
    
    static bool cmp(vector<int>&u, vector<int>&v)
    {
        return u[1]<v[1];
    }
        
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(), cmp);
        int i,count=1, arrow = points[0][1];
        
//         for(i=0; i<points.size(); i++)
//             cout<<"["<<points[i][0]<<", "<<points[i][1]<<"], ";
            
        for(i=1; i<points.size(); i++)
        {
            if(arrow<points[i][0])
            {
                count++;
                arrow=points[i][1];
            }
        }
        
        return count;
            
    }
};