class Solution {
public:
    
    int ans;
    
    void merge(vector<int> &nums, int l, int mid, int h)
    {
        int i=l, j=mid+1;
        while(i<=mid && j<=h)
        {
            if(ceil(nums[i]/2.0)>nums[j])
            {
                // cout<<"here ";
                ans+=mid-i+1;
                j++;
            }
            
            else
                i++;
        }
        
        sort(nums.begin()+l, nums.begin()+h+1);

//         cout<<endl;
//         cout<<"============================================="<<endl;
//         cout<<l<<" "<<mid<<" "<<h<<" "<<ans<<endl;
//         for(i=0; i<nums.size(); i++)
//             cout<<nums[i]<<" ";
        
//         cout<<endl;
        
//         [2147483647,2147483647,-2147483647,-2147483647,-2147483647,2147483647]
    }
    
    void solve(vector<int> &nums, int l, int h)
    {
        if(l<h)
        {
            int mid = (l+h)/2;
            solve(nums, l, mid);
            solve(nums, mid+1, h);
            merge(nums, l, mid, h);
        }
    }
        
    int reversePairs(vector<int>& nums) {
        // modified merge sort
        
        ans=0;
        solve(nums, 0, nums.size()-1);
        return ans;
        
    }
};