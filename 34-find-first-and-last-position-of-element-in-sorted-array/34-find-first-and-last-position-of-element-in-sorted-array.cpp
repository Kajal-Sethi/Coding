class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
//         use binary search
        vector<int> ans;
        int low=0, high=nums.size(), mid;
        
        if(nums.size()==0)
        {
            ans={-1,-1};
            return ans;
        }
        
        while(low<high)
        {
            mid = (low+high)/2;
            if(nums[mid]==target)
                break;
            
            else if(nums[mid]<target)
                low=mid+1;
            
            else
                high=mid;
        }
        
        if(nums[mid]!=target)
            ans={-1,-1};
        
        else
        {
            int low1=mid, high1=mid;
            
            // on left side
            while(low<=high1)
            {
                mid = (low+high1)/2;
                if(nums[mid]==target)
                {
                    if(mid-1==-1 || nums[mid-1]!=target)
                    {
                        ans.push_back(mid);
                        break;
                    }
                    
                    else
                        high1=mid;                        
                }

                else
                    low=mid+1;

            }
            
            // cout<<"done done ";
             // on right side
            while(low1<=high)
            {
                mid = (low1+high)/2;
                if(nums[mid]==target)
                {
                    if(mid+1==nums.size() || nums[mid+1]!=target)
                    {
                        ans.push_back(mid);
                        break;
                    }
                    
                    else
                        low1=mid;                        
                }

                else
                    high=mid;

            }
        }
        
        return ans;
    }
};