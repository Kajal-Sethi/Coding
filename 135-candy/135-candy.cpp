class Solution {
public:
    int candy(vector<int>& rate) {
        // use min heap
        vector<int>candies(rate.size(),1);
        int i;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
          
        for(i=0; i<rate.size(); i++)
            pq.push({rate[i], i});
        
        while(!pq.empty())
        {
            // val, index
            pair<int, int> curr = pq.top();
            cout<<curr.first<<" "<<curr.second<<endl;
            pq.pop();
            
            if(curr.second+1<rate.size() && rate[curr.second]>rate[curr.second+1] && curr.second-1>=0 && rate[curr.second]>rate[curr.second-1])
            {
                // find konsa rate bada he 
                int maxx=max(candies[curr.second+1], candies[curr.second-1]);
                candies[curr.second] = maxx+1;
            }
            
            else if(curr.second+1<rate.size() && rate[curr.second]>rate[curr.second+1])
            {
                candies[curr.second] = candies[curr.second+1]+1;
            }
            
            else if(curr.second-1>=0 && rate[curr.second]>rate[curr.second-1])
            {
                candies[curr.second] = candies[curr.second-1]+1;
            }
            
            else
                continue;
        }
        
        int weneed=0;
        for(i=0; i<candies.size(); i++)
        {
            cout<<candies[i]<<" ";
            weneed+=candies[i];
        }
        return weneed;
    }
};