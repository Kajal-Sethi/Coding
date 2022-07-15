class Solution {
public:
    
    // returns max area
    int solve(vector<vector<int>>& grid, int i, int j)
    {
        if(grid[i][j]==0)
            return 0;
        
        int row[] = {0,0,1,-1};
        int col[] = {-1,1,0,0};
        int k=0;
        
        grid[i][j]=0;
        int sum=1;
        while(k<4)
        {
            sum=sum+solve(grid,i+row[k], j+col[k]);
            k++;
        }
        
        return sum;
    }
        
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        vector<int> temp(grid[0].size(),0);
        grid.insert(grid.begin(), temp);
        grid.push_back(temp);
        int i,j;
        
        for(i=0; i<grid.size(); i++)
        {
            grid[i].insert(grid[i].begin(),0);
            grid[i].push_back(0);
        }
            
        int minn = 0, sum;
        for(i=1; i<grid.size()-1; i++)
        {
            for(j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1)
                {
                    sum = solve(grid, i, j);
                    // cout<<i<<" "<<j<<" "<<sum<<endl;
                    minn = max(minn, sum);
                }
                
                else continue;
            }
        }
        
        return minn;
    }
};