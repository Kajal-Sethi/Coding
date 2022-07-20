class Solution {
public:
    
    int max_area_hist(vector<int> &arr, int n)
    {
        vector<int> left, right;
        int i, maxx=0;
        stack<int> st;
        
        i=0;
        while(i<n)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
                
            if(st.empty())
                left.push_back(i+1);
            
            else
                left.push_back(i-st.top());
            
            st.push(i);
            i++;
        }
        
        i--;
        while(!st.empty())
            st.pop();
            
        while(i>=0)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
                
            if(st.empty())
                right.push_back(n-1-i);
            
            else
                right.push_back(st.top()-i-1);
            
            st.push(i);
            i--;
        }
        reverse(right.begin(), right.end());
        
        for(i=0; i<n; i++)
        {
            left[i]+=right[i];
            left[i]*=arr[i];
            maxx = max(maxx, left[i]);
        }
        
        return maxx;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int ans=0, maxx=0, i, j, n=matrix.size(), m=matrix[0].size();
        
        vector<int> arr;
        
        for(j=0; j<m; j++)
            arr.push_back(matrix[0][j]-'0');
            
        ans = max_area_hist(arr, m);
        maxx = max(maxx, ans);
        
        for(i=1; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(matrix[i][j]=='1')
                    arr[j]++;
    
                else
                    arr[j]=0;
            }
            ans = max_area_hist(arr, m);
            maxx = max(maxx, ans);
        
        }
        return maxx;
    }
};