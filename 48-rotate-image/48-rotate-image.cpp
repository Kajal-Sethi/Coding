class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose and reverse
        int i, j, k, n=matrix.size();
        
        // do just for upper half or lower half
        for(i=0; i<n; i++)
            for(j=i; j<n; j++)
                swap(matrix[i][j], matrix[j][i]);
        
        for(i=0; i<n; i++)
        {
            for(j=0, k=n-1; j<k; j++,k--)
                swap(matrix[i][j], matrix[i][k]);
            // cout<<endl;
        }
    }
};