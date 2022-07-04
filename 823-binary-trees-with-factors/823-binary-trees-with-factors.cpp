class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        // singles + (node having same children) + (node having different children)  
        sort(arr.begin(), arr.end());
        vector<long long> dp(arr.size(),1);
        long long i, total=1;
        
        dp[0]=1;
        for(i=1; i<arr.size(); i++)
        {
          //  vector<int> vis(arr.size(),0);
            for(int j=0; j<i; j++)
            {
                // we have to find the miltiplications for arr[i]
                if(arr[i]%arr[j]!=0)
                    continue;
                
                else
                {
                    int num = arr[i]/arr[j];
                    // num in arr 
                    vector<int>:: iterator it;
                    it = find(arr.begin(), arr.end(), num);
                    
                    if(it==arr.end())
                        dp[i];
                    
                    else
                    {
                        // if num is present
                        dp[i]+= dp[j] * dp[it-arr.begin()];
                    }
                }
            }
            
            if(dp[i]==0)
                dp[i]=1;
            
            total+=dp[i];
        }
        
        
        
        return total%1000000007;
    }
};