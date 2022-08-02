class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        int i;
        
        if(nums.size()==0)
            return 0;
        
        for(i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        
        int count=1, maxx=1;
        
        auto it = mp.begin(), temp = mp.begin();
        it++;
        for(; it!=mp.end(); it++, temp++)
        {
            if(it->first-1==temp->first)
                count++;
            
            else
                count=1;
            
            maxx=max(maxx, count);
        }
        return maxx;
        
    }
};