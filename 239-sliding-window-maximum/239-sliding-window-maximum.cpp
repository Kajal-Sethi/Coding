class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>>pq;
        int i, start=0, end=k-1;
        vector<int> ans;
        
        // value, index
        for(i=0; i<k-1; i++)
            pq.push({nums[i], i});
        
        while(end<nums.size())
        {
            pq.push({nums[end], end});
         
            pair<int, int> use = pq.top();
            while(use.second<start)
            {
                // cout<<use.second<<" ";
                pq.pop();
                use = pq.top();
            }
            
            ans.push_back(use.first);
            
            start++;
            end++;
        }
        
        return ans;
        
    }
};