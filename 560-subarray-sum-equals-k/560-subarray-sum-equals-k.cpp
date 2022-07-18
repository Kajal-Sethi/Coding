class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i, start=0, end=0, sum=0, count=0;
        // vector<int> sum(nums.size(), 0);
        map<int, int> mp;
        mp[0]=1;
        for(i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            int f = sum-k;
            
            if(mp.find(f)!=mp.end())
                count+=mp[f];
            
            mp[sum]++;
        }

        return count;
    }
};