class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // tripplet pairs with sum 0
//          use binary search. result in O(n^2)
        vector<vector<int>> ans;
        map<vector<int>, int> mp;
        
        sort(nums.begin(), nums.end());
        
        int i, j, k, sum;
        for(i=0; i<nums.size()-2; i++)
        {
            vector<int> temp;
            j=i+1;
            k=nums.size()-1;
            
            while(j<k)
            {    
                sum = nums[j]+nums[k];
                if(sum+nums[i]==0)
                {
                    // temp.push_back({nums[i], nums[j], nums[k]});
                    mp[{nums[i], nums[j], nums[k]}]= 1;
                    k--;
                    j++;
                }
                
                else if(sum+nums[i]<0)
                    j++;
                
                else
                    k--;
            }
            
        }
        
        for(pair<vector<int>, int> temp:mp)
            ans.push_back(temp.first);
        
        return ans;        
    }
};