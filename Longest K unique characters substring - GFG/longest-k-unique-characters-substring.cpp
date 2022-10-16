//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int st=0, end=0, ans=0, found=0;
        map<char, int> mp;
        
        while(end<s.size())
        {
            mp[s[end]]++;
            
            if(mp.size()>=k)
                found=1;
                
            while(mp.size()>k)
            {
                mp[s[st]]--;
                if(mp[s[st]]==0)
                    mp.erase(s[st]);
                
                st++;
            }
                
            ans = max(ans, end-st+1);
            end++;
        }
        
        if(found==0)
            return -1;
            
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends