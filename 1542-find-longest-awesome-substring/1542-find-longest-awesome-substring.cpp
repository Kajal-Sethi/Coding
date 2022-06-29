class Solution {
public:
    int longestAwesome(string s) {
        // mask, index
        map<int, int> mp;
        
        // mask can go upto 2^10 at max ie total diff masks are 1024
        int end, start, mask=0, ans=0;
        
        mp[mask]=-1;
        // If two masks are different by one bit, that means that there is one odd count number in the substring. we set bit in the mask corresponding to s[i] index
        for(start=0; start<s.size(); start++)
        {
            mask = mask^(1<<(s[start]-48));
            
            // mask was not found before
            if(mp.find(mask) == mp.end())
                mp[mask] = start;
            
            // if the mask was already present update the max length
            else
                ans = max(ans, start-mp[mask]-1);
            
            // for every mask we want to flip one bit and check if that has already occured and update the max length accordingly
            for(int j=0; j<=9; j++)
            {
                if(mp.find(mask^1<<j)!=mp.end())
                    ans = max(ans, start-mp[mask^1<<j]-1);
            }
        }
        
        return ans+1;
    }
};