class Solution {
public:
    
    long long t[20001][6];
    long long solve(int n, int index, int prev)
    {
        int a=0, e=1, i=2, o=3, u=4;
        if(index==n)
            return 1;
        
        if(t[index][prev]!=-1)
            return t[index][prev];
        
        
        if(prev==5)
            return t[index][prev] = ((solve(n, index+1, a)%1000000007 + solve(n, index+1, e)%1000000007)%1000000007 + (solve(n, index+1, i)%1000000007 + solve(n, index+1, o)%1000000007)%1000000007 +solve(n, index+1, u)%1000000007)%1000000007;
        
        else if(prev==a)
        {
            return t[index][prev] = solve(n, index+1, e)%1000000007;
        }
        
        else if(prev==e)
        {
            return t[index][prev] = (solve(n, index+1, a)%1000000007 + solve(n, index+1, i)%1000000007)%1000000007;
        }
        
        else if(prev==i)
        {
            return t[index][prev]= ((solve(n, index+1, a)%1000000007 + solve(n, index+1, e)%1000000007)%1000000007 +( solve(n, index+1, o)%1000000007 +solve(n, index+1, u)%1000000007)%1000000007)%1000000007;
        }
        
        else if(prev==o)
        {
            return t[index][prev] = (solve(n, index+1, u)%1000000007 + solve(n, index+1, i)%1000000007)%1000000007;
        }
        
        else 
        {
            return t[index][prev] = solve(n, index+1, a)%1000000007;
        }
        
    }
    
    int countVowelPermutation(int n) {
        
        memset(t,-1,sizeof(t));
        return solve(n, 0, 5);
    }
};