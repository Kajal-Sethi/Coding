//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    void lps(string &s, vector<int> &lps_a) 
    {
	    int i, j;
	    
	    j=1;
	    i=0;
	    while(j<s.size())
	    {
	        if(s[i]==s[j])
	        {
	            lps_a[j] = i+1;
	            i++;
	            j++;
	        }
	        
	        else
	        {
	            while(s[i]!=s[j] && i!=0)
	                i = lps_a[i-1];
	            
	            if(s[i]==s[j])
    	        {
    	            lps_a[j] = i+1;
    	            i++;
    	            j++;
    	        }
    	        
    	        else
    	        {
    	            lps_a[j] = 0;
        	        j++;
	            }
	        }
	    }
	}
	
    vector <int> search(string pat, string txt)
    {
        vector<int> lps_a(pat.size(), 0), ans;
        lps(pat, lps_a);
        
        int i, j, count=0;
	    
	    j=0;
	    i=0;
	    while(j<txt.size())
	    {
	        if(pat[i]==txt[j])
	        {
	            i++;
	            j++;
	        }
	        
	        else
	        {
	            while(pat[i]!=txt[j] && i!=0)
	                i = lps_a[i-1];
	            
	            if(pat[i]==txt[j])
    	        {
    	            i++;
    	            j++;
    	        }
    	        
    	        else
        	        j++;
	        }
	        
	        if(i==pat.size())
	        {
	            ans.push_back(j-pat.size()+1);
	            i=lps_a[i-1];
	        }
	    }
        
        if(ans.size()==0)
            return {-1};
            
        return ans;
    }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends