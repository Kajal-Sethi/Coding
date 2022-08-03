class Solution {
public:
    
    double use(double x, int n) {
        
        if(n==0)
            return 1;
        
        if(n==1)
            return x;
        
        if(n%2==0)
        {
            double val = x*x;
            return use(val, n/2);
        }
        
        else
        {
            double val = x*x;
            return use(val, n/2) * x;
        }
    }
    
    
    double myPow(double x, int n) {
        
        double ans = use(x, abs(n));
        
        if(n>=0)
            return ans;
        return 1/ans;
    }
};