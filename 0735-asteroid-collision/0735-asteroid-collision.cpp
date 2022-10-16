class Solution {
public:
    vector<int> asteroidCollision(vector<int>& cars) {
    // for pos num find the next greater or eq -ve num
    // for -ve num find the next greater or eq +ve num on the left
    vector<int> ans, rev;    
    int i, n = cars.size();
    stack<int> st;

    i=0;
    while(i<n && cars[i]<0)
        ans.push_back(cars[i++]);
        
    if(i==n)
        return ans;
    cout<<"---";

    while(i<n)
    {
        if(cars[i]>0)
            st.push(i);
        
        else
        {
            int f=0;
            while(!st.empty() && abs(cars[st.top()])<abs(cars[i]))
            {
                if(abs(cars[st.top()]) == abs(cars[i]))
                    f=1;
                    
                st.pop();
            }
            
            if(!st.empty() && abs(cars[st.top()]) == abs(cars[i]))
            {
                st.pop();
                i++;
                continue;
            }    
            
            if(st.empty() && f==0)
                ans.push_back(cars[i]);
        }

        i++;
    }
    
    while(!st.empty())
    {
        rev.push_back(cars[st.top()]);
        st.pop();
    }
    
    reverse(rev.begin(), rev.end());
    for(auto ad: rev)
        ans.push_back(ad);
        
    return ans;
}
};