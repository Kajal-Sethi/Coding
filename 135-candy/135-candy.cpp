class Solution {
public:
    int candy(vector<int>& rate) {
        // use min heap
        vector<int>candies(rate.size(),1);
        int i, need=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
          
        for(i=0; i<rate.size(); i++)
            pq.push({rate[i], i});
        
        while(!pq.empty())
        {
            // val, index
            pair<int, int> curr = pq.top();
            pq.pop();
            
            if(curr.second+1<rate.size() && rate[curr.second]>rate[curr.second+1] && curr.second-1>=0 && rate[curr.second]>rate[curr.second-1])
            {
                // find konsa rate bada he 
                int maxx=max(candies[curr.second+1], candies[curr.second-1]);
                candies[curr.second] = maxx+1;
                need+=maxx+1;
            }
            
            else if(curr.second+1<rate.size() && rate[curr.second]>rate[curr.second+1])
            {
                candies[curr.second] = candies[curr.second+1]+1;
                need+=candies[curr.second+1]+1;
            }
            
            else if(curr.second-1>=0 && rate[curr.second]>rate[curr.second-1])
            {
                candies[curr.second] = candies[curr.second-1]+1;
                need+=candies[curr.second-1]+1;
            }
            else
            {    
                need+=candies[curr.second];
                continue;
            }
        }
        
        return need;
    }
};