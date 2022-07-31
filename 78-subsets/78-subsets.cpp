class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums, int index, vector<int> output)
    {
        if(index>=nums.size())
        {
            ans.push_back(output);
            return;
        }
        
        vector<int> copy;
        copy=output;
        copy.push_back(nums[index]);
        
        solve(nums, index+1, output);
        solve(nums, index+1, copy);
    }
        
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        solve(nums, 0, output);
        return ans;
    }
};