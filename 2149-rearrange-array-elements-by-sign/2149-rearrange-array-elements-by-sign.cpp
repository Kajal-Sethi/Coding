class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        vector<int> ans;
        int i=0;
        
        for(i=0; i<nums.size(); i++)
        {
            if(nums[i]>0)
                pos.push_back(i);
            
            else
                neg.push_back(i);
        }
        
        int p=0, n=0; 
        // if(pos[p]<neg[n])
        // {
            ans.push_back(nums[pos[p]]);
            p++;
            while(p+n<nums.size())
            {
                if(p<=n)
                {
                    ans.push_back(nums[pos[p]]);
                    p++;
                }    
                
                else
                {
                    ans.push_back(nums[neg[n]]);
                    n++;
                }  
            }
        // }
        
//         else
//         {
//             ans.push_back(nums[neg[n]]);
//             n++;
//             while(p+n<nums.size())
//             {
//                 if(p<=n)
//                 {
//                     ans.push_back(nums[pos[p]]);
//                     p++;
//                 }    
                
//                 else
//                 {
//                     ans.push_back(nums[neg[n]]);
//                     n++;
//                 }  
//             }
//         }
        return ans;
    }
};