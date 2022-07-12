// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// start from end of B
    	int end_a = A.length()-1, end_b = B.length()-1, count=0, i;
    	
    // 	 check that both strings have same elements
    	map<char, int>mp;
    	for(i=0; i<=end_a; i++)
    	    mp[A[i]]++;
    	    
    	for(i=0; i<=end_b; i++)
    	    mp[B[i]]--;
    	    
    	for(pair<char, int> use:mp)
    	    if(use.second!=0)
    	        return -1;
    	    
    	while(end_a>=0 && end_b>=0)
    	{
    	    if(A[end_a] == B[end_b])
    	    {
    	        end_a--;
    	        end_b--;
    	    }
    	    
    	    else
    	    {
    	        count++;
    	        end_a--;
    	    }
    	}
    
        return count;	
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends