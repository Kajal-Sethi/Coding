//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    int i, j, maxx=0;
	    vector<int> lps_a(s.size(), 0);
	    
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
	        
	       // maxx = max(maxx, lps_a[j]);
	    }
	    
	   // for(auto aa:lps_a)
	   //     cout<<aa<<" "; cout<<endl;
	    return lps_a[s.size()-1];
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends