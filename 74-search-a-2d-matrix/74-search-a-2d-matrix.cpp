class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // use b.search in 1st col to find col bigger than target
        
        int mid, rows = matrix.size(), col = matrix[0].size(), l=0, h=matrix.size()-1;
        
        while(l<=h)
        {
            mid = (l+h)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][col-1])
                break;
            
            else if(target<matrix[mid][0])
                h=mid-1;
            
            else
                l=mid+1;
        }
        
        l=0;
        h=col-1;
        int use=mid;
        while(l<=h)
        {
            mid = (l+h)/2;
            if(target==matrix[use][mid])
                return true;
            
            else if(target<matrix[use][mid])
                h=mid-1;
            
            else
                l=mid+1;
        }
        
        return false;
    }
};