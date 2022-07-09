class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int, int>>pq;       // value, index
        int t[nums.size()+1], i, j=1;
        
        for(i=0; i<nums.size(); i++)
            t[i]=INT_MIN;

        t[0]=nums[0];
        
        // instead of adding all one by one we can use sliding window/ heap to find max
        while(j<nums.size())
        {
            int range = j-k>0? j-k:0; 
            
            pq.push({t[j-1], j-1});
            
            while(1)
            {
                pair<int, int>use=pq.top();
                if(use.second>=range && use.second<j)
                    break;
                
                else
                    pq.pop();
            }
            t[j]=nums[j]+pq.top().first;
            j++;
        }
        return t[nums.size()-1];
    }
};