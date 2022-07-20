class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // we need next smaller element to the left and to the right for every element
        vector<int> left, right;
        stack<int> st;
        int i, n=heights.size(); 
        
        // to the right
        i = n-1;
        while(i>=0)
        {
            while(!st.empty() && heights[st.top()]>=
                  heights[i])
                st.pop();
            
            if(st.empty())
                right.push_back(n-i);
            
            else
                right.push_back(st.top()-i);
            
            st.push(i);
            i--;
        }
        reverse(right.begin(), right.end());
        
        while(!st.empty())
            st.pop();
        
        i=0;
        while(i<n)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            
            if(st.empty())
                left.push_back(i);
            
            else
                left.push_back(i-st.top()-1);
            
            st.push(i);
            i++;
        }
        
        int maxx=0;
        for(i=0; i<n; i++)
        {    
            left[i]+=right[i];
            // cout<<left[i]<<" ";
            left[i] = left[i]*heights[i];
            maxx = max(maxx, left[i]);
        }
        
        return maxx;
    }
};