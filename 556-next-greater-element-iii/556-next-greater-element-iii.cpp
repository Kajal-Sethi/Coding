class Solution {
public:
    int nextGreaterElement(int n) {
        long long int num = n;
        
        // 932541
        // 934125
        // vector<int> str;
        
        string str = to_string(n);
        int dig=0, i, j;
        
//         while(n>0)
//         {
//             str.push_back()
            
//         }
        // cout<<str;
        for(i=str.size()-2; i>=0; i--)
            if(str[i+1]-'0'>str[i]-'0')
                break;
        // cout<<i;
        if(i==-1 && str[1]<=str[0])        //reverse the num
        {
            // cout<<"here";
            reverse(str.begin(),str.end());
            return -1;
        }
            
        else
        {
            for(j=str.size(); j>i; j--)
                if(str[j]>str[i])
                {
                    swap(str[i], str[j]);
                    break;
                }
            
            reverse(str.begin() + i+1,str.end());            
        }
        
        num=0;
        i=0;
        while(i<str.size())
        {
            num=num*10+(str[i]-'0');
            i++;
        }
        
        if(num>2147483647)
            return -1;
        
        return num;
    }
};