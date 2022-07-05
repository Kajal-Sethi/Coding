class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        int i, maxx=0, count=1;
        
        if(nums.size()==0 || nums.size()==1)
            return nums.size();
        
        for(i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        
         auto it=mp.begin(), start = mp.begin();
        
        it++;
        while(it!=mp.end())
        {
            if(it->first-1 == start->first)
            {
                count++;
            }
            else
                count=1;
            
            maxx=max(maxx, count);
            it++;
            start++;
        }
        
        return max(count,maxx);
        
    }
};