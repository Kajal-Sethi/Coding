class Solution {
public:
    
    // returns max sum of a subarray
    int solve(vector<int>& nums, int capacity)
    {
        int i, sum=0, count=0;
        for(i=0; i<nums.size(); i++)
        {
            if(sum+nums[i]<capacity)
                sum=sum+nums[i];
            
            else if(sum+nums[i]==capacity)
            {
                count++;
                sum=0;
            }
            
            else
            {
                sum=nums[i];
                count++;
            }
        }
        
        if(sum!=0 && sum<=capacity)
            count++;

        return count;
    }
        
    int splitArray(vector<int>& nums, int m) {
        // min sized array with max sum is largest number
        // with m bags return the min capacity req
        
        int i, sum=nums[0], minn=nums[0], mid;
        
        for(i=1; i<nums.size(); i++)
        {
            sum+=nums[i];
            minn=max(minn, nums[i]);
        }
        
        if(m==1)
            return sum;
        
        if(nums.size()<=m)
            return minn;
        
        while(minn<sum)
        {
            // if mid is the capacity of each bag do we get m bags
            mid=(minn+sum)/2;
            if(solve(nums, mid)<=m)
                sum=mid;

            else
            {
                minn=mid+1;
                cout<<minn;
            }
        }
        
//         cout<<endl<<" val is "<<solve(nums, 6);
        
//         cout<<solve(nums, 6);
        return minn;
    }
};