class Solution {
public:
    
    
//     long long solve(string str, int index)
//     {
//         if(index<=0)
//             return 1;

//         int i = str[index]-'0';        
//         int j = str[index-1]-'0';
//         int num = j*10 + i;
        
//         if(t[index]!=-1)
//             return t[index];
        
//         if(i==0)
//             return t[index] = (solve(str, index-2));

//         else if(num>26 || j==0)
//             return t[index] = (solve(str, index-1));

//         else
//             return t[index] = (solve(str, index-1)+solve(str, index-2));

//     }

    int numDecodings(string A) {
        long long t[A.size()+1];
        // memset(t,-1,sizeof(t));
        int i;
        if(A[0]=='0')
            return 0;
        for(i=1; i<A.size(); i++)
            if(A[i]=='0' && (A[i-1]-'0'>2 || A[i-1]-'0'==0))
                return 0;

        t[0]=1;
        t[1]=1;
        for(i=2; i<=A.size(); i++)
        {
            int num1, num2, num;
            num1 = A[i-1]-'0';        
            num2 = A[i-2]-'0';
            num = num2*10 + num1;

            if(num1==0)
                t[i] = t[i-2];

            else if(num>26 || num2==0)
                t[i] = t[i-1];

            else
                t[i] = t[i-1]+t[i-2];

        }
        return t[A.size()];
        
        // return (solve(A, A.size()-1));

        // 12 can be considered as 1,2 and 12
        // 0 has to be linked with prev num
    }

};