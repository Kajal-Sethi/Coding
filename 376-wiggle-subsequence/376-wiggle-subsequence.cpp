class Solution {
public:
    
    // return the length of longest string
    unordered_map<string, int>mp;
    int solve(vector<int>& nums, int index, int turn, int prev)
    {
        if(index>=nums.size())
            return 0;
        
        string a=to_string(index), b=to_string(turn), c=to_string(prev);
        
        a.push_back(' ');
        a=a+b;
        a.push_back(' ');
        a=a+c;
        
        if(mp.find(a)!=mp.end())
            return mp[a];
        
        if(prev==INT_MAX)
        {
            return mp[a] = max(solve(nums, index+1, turn, prev), solve(nums, index+1, -turn, nums[index])+1);
        }
        
        if(turn == -1)  // difference <0
        {
            if(prev-nums[index]<0)
                return mp[a] = max(solve(nums, index+1, turn, prev), solve(nums, index+1, -turn, nums[index])+1);             
            else
                return mp[a] = solve(nums, index+1, turn, prev);
        }
        
        else        // difference >0
        {
            if(prev-nums[index]>0)
                return mp[a] = max(solve(nums, index+1, turn, prev), solve(nums, index+1, -turn, nums[index])+1);             
            else
                return mp[a] = solve(nums, index+1, turn, prev);
        }
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        // a variation of LIS
        if(nums.size()==0)
            return 0;
        
        int neg = solve(nums, 0, -1, INT_MAX);
        int pos = solve(nums, 0, 1, INT_MAX);
        // ek baar +1 and ek baar -1 se call krlo
        return max(neg, pos);
        
    }
};