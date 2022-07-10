class Solution {
public:
    
    int minJumps(vector<int>& arr) {
        // every index has miltiple choices. ie move to i+1 or i-1 or index with same val
        
        if(arr.size()==1)
            return 0;
        
        unordered_map<int, vector<int>> mp;
        queue<int> q;
        vector<int> cost(arr.size(), INT_MAX), vis(arr.size(), 0);
        int i, n = arr.size();
        
//         mp[arr[0]].push_back(1);
//         mp[arr[arr.size()-1]].push_back(arr.size()-1);
        
        for(i=0; i<n; i++)
            mp[arr[i]].push_back(i);
        
        vis[n-1] = 1;
        q.push(n-1);
        cost[n-1]=0;
        
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            // cout<<top<<" ";
            vector<int> use = mp[arr[top]];
            
            for(int i:use)
            {
                if(vis[i]==0)
                {
                    vis[i]=1;
                    q.push(i);
                    cost[i] = cost[top]+1;
                    if(i==0)
                        return cost[i];
                }
            }
            
            if(top-1==0)
                return cost[top]+1;
            
            if(top-1>0 && vis[top-1]==0)
            {
                vis[top-1]=1;
                q.push(top-1);
                cost[top-1] = cost[top] + 1;
                // cout<<top-1<<" ";
            }
            
            if(top+1<arr.size() && vis[top+1]==0)
            {
                vis[top+1]=1;
                q.push(top+1);
                cost[top+1] = cost[top] + 1;
                
                if(top-1==0)
                    return cost[0];
            }
        }
        
        return -1;
        
//         vis[0] = 1;
//         q.push(0);
//         cost[0]=0;
        
//         while(!q.empty())
//         {
//             int top = q.front();
//             q.pop();
//             // cout<<top<<" ";
//             vector<int> use = mp[arr[top]];
            
//             for(int i:use)
//             {
//                 if(vis[i]==0)
//                 {
//                     vis[i]=1;
//                     q.push(i);
//                     cost[i] = cost[top]+1;
//                     if(i==arr.size()-1)
//                         return cost[i];
//                 }
//             }
            
//             if(top-1>0 && vis[top-1]==0)
//             {
//                 vis[top-1]=1;
//                 q.push(top-1);
//                 cost[top-1] = cost[top] + 1;
//             }
            
//             if(top+1<arr.size() && vis[top+1]==0)
//             {
//                 vis[top+1]=1;
//                 q.push(top+1);
//                 cost[top+1] = cost[top] + 1;
                
//                 if(top+1==arr.size()-1)
//                     return cost[arr.size()-1];
//             }
//         }
        
//         return -1;
    }
};