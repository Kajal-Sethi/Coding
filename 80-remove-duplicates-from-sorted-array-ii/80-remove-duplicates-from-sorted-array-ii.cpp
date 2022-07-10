class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3)
            return nums.size();
        
        int curr=1, prev=0, next=2, count=0;
        
        while(next<nums.size())
        {
            if(nums[prev]==nums[next])
            {
                count++;
                nums.erase(nums.begin()+prev);
                
//                 if(next+1<nums.size() && nums[next+1]==nums[next])
//                 {
//                     prev=curr;
//                     curr=next;
//                     next=next+1;
//                 }
                
//                 else if(next+3<nums.size())
//                 {
//                     prev=next+1;
//                     curr=prev+1;
//                     next=curr+1;
//                 }
                
//                 else
//                     break;
            }
            
            else
            {
                prev++;
                curr++;
                next++;
            }
        }
            
        return nums.size();
    }
};