class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>arr(256,0);
        int end=0, start=0, count=0, maxx=0;
        
        if(s.length()==0)
            return 0;
        
        while(end<s.length())
        {
            arr[s[end]+128]++;
            count++;
            
            while(arr[s[end]+128]>1)
            {
                arr[s[start]+128]--;
                start++;
                count--;
            }
            
            maxx=max(maxx, count);
            end++;
        }
        return maxx;
    }
};