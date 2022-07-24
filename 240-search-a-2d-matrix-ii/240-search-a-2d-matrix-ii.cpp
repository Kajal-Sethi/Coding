class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int turns=0, col = matrix[0].size()-1, row = 0;
        
        while(col>=0 && row<matrix.size())
        {
            turns++;
            if(matrix[row][col]==target)
                return true;
            
            if(matrix[row][col]>target)
                col--;
            
            else
                row++;
            // if(col<0)
            //     break;
            
            // if(matrix[row][col]<target)
                
            // cout<<row<<" "<<col<<endl;
        }
        return false;
        
    }
};