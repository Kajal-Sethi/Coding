class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i, maxx=1, count=1, num=nums[0];
        
        for(i=1; i<nums.size(); i++)
        {
            if(nums[i]==nums[i-1])
                count++;
            
            else
            {
                if(maxx<count)
                {
                    maxx=count;
                    num=nums[i-1];
                }
                count=1;
            }
        }
        
        if(maxx<count)
        {
            maxx=count;
            num=nums[i-1];
        }
        
        return num;
    }
};