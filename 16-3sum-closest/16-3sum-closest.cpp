class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i, j, k, sum, exact= 20002;
        
        sort(nums.begin(), nums.end());
        
        for(i=0; i<nums.size()-2; i++)
        {
            j = i+1;
            k = nums.size()-1;
            
            while(j<k)
            {
                sum = nums[j]+nums[k]+nums[i];
                
                if(sum==target)
                    return target;
                
                else if(sum>target)
                {
                    if(abs(target-exact)>abs(target-sum))
                        exact = sum;
                    
                    k--;
                }
                
                else
                {
                    
                    if(abs(target-exact)>abs(target-sum))
                        exact = sum;

                    j++;
                }
                
            }
        }
        // cout<<maxx;
        return exact;
    }
};