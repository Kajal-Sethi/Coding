class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // priority_queue<int, vector<int>, greater<int>> pq;
        
        priority_queue<int> pq;
        int i, j;
        
        for(i=0; i<matrix.size(); i++)
            for(j=0; j<matrix[0].size(); j++)
            {
                pq.push(matrix[i][j]);
                if(pq.size()>k)
                    pq.pop();
            }    
        return pq.top();
    }
};