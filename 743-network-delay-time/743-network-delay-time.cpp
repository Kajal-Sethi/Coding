class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // directed graph
        // the maximum cost path of the tree. TOPOLOGICAL SORT
        // k is the root
        
        
        vector<pair<int,int>> adj[n];
        vector<int> vis(n,0), cost(n, INT_MAX);
        int i;
        // dist/wt, index 
        priority_queue<pair<int,int>,  vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(i=0; i<times.size(); i++)
            adj[times[i][0]-1].push_back({times[i][1]-1, times[i][2]});
        
        cost[k-1] = 0;
        vis[k-1] = 1;
        pq.push({0, k-1});
        
        // adj: index, wt
        // pq: dist/wt, index 
        while(!pq.empty())
        {
            pair<int,int> curr = pq.top();
            pq.pop();
            // cout<<curr.second<<" ";
            
            for(pair<int,int> use:adj[curr.second])
                // if(!vis[use.second])
            {
                // adj and use: index, wt
                // pq and curr: dist/wt, index 
                if(use.second + curr.first < cost[use.first])
                {
                    cost[use.first] = use.second + curr.first;
                    pq.push({cost[use.first], use.first});
                    vis[use.first]=1;
                }
            }                
        }
        
        for(i=0; i<n; i++)
            if(vis[i]==0)
                return -1;
        
        int maxx=cost[0];
        for(i=1; i<n; i++)
            maxx=max(maxx, cost[i]);
        return maxx;
    }
};