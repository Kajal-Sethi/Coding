class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        int i, maxx=1, count=1, num=nums[0];
        
        for(i=1; i<nums.size(); i++)
        {
            if(nums[i]==nums[i-1])
                count++;
            
            else
            {
                if(count>nums.size()/3)
                    ans.push_back(nums[i-1]);

                count=1;
            }
        }
        
        if(count>nums.size()/3)
            ans.push_back(nums[i-1]);
        
        return ans;
    }
};