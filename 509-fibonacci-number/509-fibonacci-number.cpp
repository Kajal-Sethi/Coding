class Solution {
public:

    int fib(int n) {
        if(n == 0 || n == 1) 
            return n; // then return 1
        
        return fib(n - 1) + fib(n - 2); // return what it wants
    }
};