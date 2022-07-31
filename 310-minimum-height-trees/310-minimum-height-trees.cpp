class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // return list of min ht trees
        // node with degree 1 are leaves
        // root node lie in longest path chain
        //  there could only be one path between any two nodes
        // For the tree-alike graph, the number of centroids is no more than 2.
        
        // we apply bfs from all the leaves.
        queue<int> q;
        vector<int> vis(n,0), indegree(n,0), ans;
        vector<int> adj[n];
        int i;
        
        if(n==1)
        {
            ans.push_back(0);
            return ans;
        }
            
        for(i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        // the nodes with indegree 1 is leaf
        
        for(i=0; i<n; i++)
            if(indegree[i]==1)
                q.push(i);
        
        while(!q.empty())
        {
            // trim leaves layer by layer
            ans.clear();
            int size = q.size();
            while(size>0)
            {
                int curr = q.front();
                q.pop();
                for(auto nei:adj[curr])
                {
                    indegree[nei]--;
                    if(indegree[nei]==1)
                        q.push(nei);
                }
                ans.push_back(curr);
                size--;
            }
        }
        return ans;
    }
};