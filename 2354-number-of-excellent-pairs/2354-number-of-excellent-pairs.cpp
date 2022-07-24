class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        set <int> s{nums.begin(), nums.end()};
        // count set bits for each number
        
        set<int>::iterator itr2;
        map<int, int> mp;
        
        for (itr2 = s.begin(); itr2 != s.end(); itr2++) 
        {
            int curr=*itr2, count=0;
            while(curr>0)
            {
                if(curr&1)
                    count++;
                curr/=2;
            }
            mp[count]++;
        }
        
        long long ans=0;
        
        map<int, int>::iterator itr, use2;
        for (itr = mp.begin(); itr != mp.end(); ++itr) {
            for (use2 = mp.begin(); use2 != mp.end(); ++use2) {                
                if(itr->first + use2->first >=k)
                 {
//                      if(itr->first != use2->first)
//                          ans+=itr->second * use2->second *2;
                     
//                      else
                         ans+=itr->second * use2->second;
                 }
            }
        }
        return ans;
        
    }
};