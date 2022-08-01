class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    
        if(nums.size()==1)
            return;

        int i, j;
        for(i=nums.size()-2; i>0; i--)
            if(nums[i+1]>nums[i])
                break;

        
        if(i==0 && nums[i+1]<=nums[i])    // reverse the entire vector
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        
        for(j=nums.size()-1; j>i; j--)
            if(nums[j]>nums[i])
                break;
            
        swap(nums[i], nums[j]);

        // reverse from i+1 to end
        for(i=i+1, j=nums.size()-1; i<j; i++, j--)    // reverse the entire vector
        {
            swap(nums[i], nums[j]);
        }

    }
};