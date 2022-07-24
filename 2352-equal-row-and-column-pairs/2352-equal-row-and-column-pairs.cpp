class Solution {
public:
    
//     bool same(vector<vector<int>>& grid, int row, int col)
//     {
//         int i;
//         for(i=0; i<grid.size(); i++)
//             if(grid[row][i]!=grid[i][col])
//                 return false;
        
//         return true;
//     }

    int equalPairs(vector<vector<int>>& grid) 
    {
        int i, j, count=0, n=grid.size();
        vector<vector<int>> trans(n, vector<int>(n,0));
            
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                trans[i][j] = grid[j][i];

        map<vector<int>, int> mp, broo;
        for(i=0; i<n; i++)
            mp[grid[i]]++;
        
        for(i=0; i<n; i++)
            broo[trans[i]]++;
        
        for(pair<vector<int>, int> finds: broo)
        {
            count+=mp[finds.first]*finds.second;
                cout<<" this "<<i;
        }
        return count;
    }
    
    
    // doesnt work well for [13 13][13 13] 
//     int equalPairs(vector<vector<int>>& grid) {
//         // for every row we will need to check every col
//         map<int, vector<pair<int, int>>> mp;
//         int i, j, count=0;
        
//         for(i=0; i<grid.size(); i++)
//             mp[grid[i][0]].push_back({i,0});
                    
//         for(i=0; i<grid.size(); i++)
//             mp[grid[0][i]].push_back({0, i});
        
//         // jo saath he usse pe call krna he
//         for(auto it: mp)
//             for(i=0; i<it.second.size()-1; i++)
//                 for(j=i+1; j<it.second.size(); j++)
//                     if(same(grid, (it.second)[i].first, (it.second)[j].second))
//                     {
//                         // cout<<(it.second)[i].first<<" "<<(it.second)[j].second<<"     "<<it.first<<endl;
//                         count++;
//                     }
//         return count;
//     }
};