class Solution {
public:
    
    vector<vector<int>> ans;
    void solve(vector<int> arr, int target,vector<int> final, int index)
    {
        if(target==0)
        {
            ans.push_back(final);
            return;
        }
        
        if(index==arr.size())
            return;
        
        // select or not select
        if(target-arr[index]>=0)
        {
            // create a new array
            vector<int> send=final;
            final.push_back(arr[index]);
            solve(arr, target-arr[index], final, index);            
            
            arr.erase(arr.begin()+index);
            solve(arr, target, send, index);
        }
        
        else
        {
            arr.erase(arr.begin()+index);
            solve(arr, target, final, index);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> final;
        solve(candidates, target, final, 0);
        
        return ans;
    }
};