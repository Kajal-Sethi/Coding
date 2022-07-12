class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // sliding window
        
        int i=0,sum=0, maxx=0,use=0, start=0, end=0;
        
        for(i=0; i<grumpy.size(); i++)
            if(grumpy[i]==0)
                sum+=customers[i];
        
        
        while(end<grumpy.size())
        {
            if(grumpy[end]==1)
                use+=customers[end];
            
            while(end-start>=minutes)
            {
                if(grumpy[start]==1)
                    use-=customers[start];
                
                start++;
            }
            
            maxx = max(maxx, use);
            end++;
        }
            
        return maxx+sum;
    }
};