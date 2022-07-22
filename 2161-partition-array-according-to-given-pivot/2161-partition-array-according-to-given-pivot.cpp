class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left, right;
        int i=0, cnt=0; 
        
        while(i<nums.size())
        {
            if(nums[i]<pivot)
                left.push_back(nums[i]);
            
            else if(nums[i]>pivot)
                right.push_back(nums[i]);
            
            else 
                cnt++;
            
            i++;
        }
        
        while(cnt>0)
        {
            left.push_back(pivot);
            cnt--;
        }
        
        i=0; 
        while(i<right.size())
        {
            left.push_back(right[i]);
            i++;
        }
        return left;
    }
};