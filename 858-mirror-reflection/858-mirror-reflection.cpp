class Solution {
public:
    int len1, len2;
    
    int solve(int p, int q, int turn)
    {
        if(len1!=0 && len1%p==0)
        {
            // cout<<len1;
            return 2;
        }
        if(len2%p==0)
        {
            return (len2/p)%2;
        }
        
        if(turn == 2)
        {
            len2=len1+q;
            return solve(p,q,1);
        }
        
        else
        {
            len1=len2+q;
            return solve(p,q,2);
        }
    }
    
    int mirrorReflection(int p, int q) {
        len1=0;
        len2 = q;
        return solve(p, q, 1);
        return 0;
    }
};