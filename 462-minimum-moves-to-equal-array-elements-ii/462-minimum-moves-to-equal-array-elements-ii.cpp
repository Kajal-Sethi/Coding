class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // shift to the median of the array
        int i, median, count=0, n=nums.size();
        sort(nums.begin(), nums.end());
        
        if(n%2==0)
            median = ceil(float(nums[n/2] + nums[n/2-1])/2);
        
        else
            median = nums[n/2];
        
        for(i=0; i<nums.size(); i++)
            count+=abs(median-nums[i]);
        
        return count;
    }
};