//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    vector<int> org(26, 0), v(26, 0);
	    int i, count=0, st=0;
	    
	    for(auto s: pat)
	        org[s-'a']++;
	        
	    for(i=0; i<pat.size(); i++)
	        v[txt[i]-'a']++;
	        
	    if(v==org)
	        count++;
	       
	    while(i<txt.size())
	    {
	        v[txt[i]-'a']++;
	        v[txt[st]-'a']--;
	        
	        if(v==org)
	            count++;
	        
	        i++;
	        st++;
	    }
	    
	    return count;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends