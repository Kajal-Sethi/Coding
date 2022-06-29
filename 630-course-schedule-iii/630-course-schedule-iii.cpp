class Solution {
public:
    
    static bool coll(vector<int>v1, vector<int> v2)
    {
        //int size = v1.size();
        if(v1[1]==v2[1])
            return v1[0]<v2[0];
        
        return v1[1]<v2[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), coll);

        // sort the array acc to last day
        priority_queue<pair<int, int>> pq;
        int start_time=0, count=0, i=0;
        while(i<courses.size())
        {
            // duration > lastday
            if(courses[i][0]>courses[i][1])
            {
                i++;
                continue;
            }
            
            if(start_time + courses[i][0] <= courses[i][1])
            {
                start_time+=courses[i][0];
                pq.push({courses[i][0], courses[i][1]});
                count++;
            }
            
            else
            {
                pair<int, int> use = pq.top();
                if(use.first > courses[i][0])
                {
                    pq.pop();
                    pq.push({courses[i][0], courses[i][1]});
                    start_time = start_time - (use.first-courses[i][0]);
                }
            }
            
            i++;
            
        }
        
        return count;
    }
};