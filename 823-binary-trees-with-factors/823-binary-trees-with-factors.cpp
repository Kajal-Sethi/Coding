class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size(), i;
        map<int, long long> dp;
        
        sort(arr.begin(), arr.end());
        for(i=0; i<n; i++)
            dp[arr[i]] = 1;
        
        for(auto it:dp)
        {
            for(i=0; arr[i]<it.first; i++)
            {
                if(it.first%arr[i]==0)
                {
                    int prod = it.first/arr[i];
                    dp[it.first]+=dp[arr[i]]*dp[prod];
                }
            }
        }
        
        long long sum=0;
        for(auto it:dp)
           sum+=it.second;
        
        return sum%int(1e9+7);
    }
};