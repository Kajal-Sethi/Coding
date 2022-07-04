// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // X xor A is min
        // set_bits(X) = set_bits(B)
        
        // find the number of set bits in B
        int c=b, total_b=0,set_b=0, d=a, total_a=0,set_a=0;
        
        while(c>0)
        {
            if(c&1)
                set_b++;
                
            total_b++;
            c=c/2;
        }
        
        while(d>0)
        {
            if(d&1)
                set_a++;
                
            total_a++;
            d=d/2;
        }
        
        int diff = abs(set_b-set_a);
        // set set_b number of bits in A from right to left
        // if set_b>set_a then set diff bits in a
        // else reset diff bits in a
        
        // cout<<diff<<" "<<set_a<<" "<<set_b<<" ";
        
        int index=0;
        if(set_b>set_a)
        {
            while(diff>0 && index<32)
            {    // int x = a&(1<<index);
            //    cout<<(1<<index)<<" ";
                if(!(a&(1<<index)))
                {
                //    cout<<diff<<" ";
                    a = a|(1<<index);
                    diff--;
                }
                index++;
            }    
        }
        
        else
        {
            while(diff>0 && index<32)
            {    
                if(a&(1<<index))
                {
                //    cout<<diff<<" ";
                    a = a^(1<<index);
                    diff--;
                }
                
                index++;
            } 
        }
        
        
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends