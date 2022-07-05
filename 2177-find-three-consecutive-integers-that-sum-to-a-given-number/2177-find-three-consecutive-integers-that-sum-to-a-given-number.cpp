class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        // divide the number by 3 to get one factor
        long long i=ceil(double(num)/3), j=floor(double(num)/3);
        vector<long long> ans;
        
   //     cout<<i<<" "<<j;
        if(i!=j)
            return ans;
        
        else
        {
            ans.push_back(i-1);
            ans.push_back(i);
            ans.push_back(i+1);
            return ans;
        }
        
    }
};