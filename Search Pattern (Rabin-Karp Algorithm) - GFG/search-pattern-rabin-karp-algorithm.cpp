//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        
        vector <int> search(string patt, string text)
        {
            vector <int> ans;
            int h=101, i, st=0;
            long long pat = 0, txt =0;
            
            for(i=0; i<patt.size(); i++)
            {
                pat+=patt[i]*pow(h, i);
                txt+=text[i]*pow(h, i);
            }
            
            
            while(i<text.size())
            {
                // cout<<patt<<" "<<text.substr(st, i-st)<<endl;
                //match the strings
                if(pat==txt && patt==text.substr(st, i-st))
                {
                    ans.push_back(st+1);

                
                txt=txt-text[st];
                txt=txt/h;
                txt+=text[i]*pow(h, patt.size()-1);

                i++;
                st++;
            }
            
            if(pat==txt && patt==text.substr(st, i-st))
                ans.push_back(st+1);
            
            if(ans.size()==0)
                return  {-1};
                
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
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends