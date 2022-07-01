class Solution {
public:
    
    // static bool val(int a, int b)
    // {
    //     return a<b;
    // }
    
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int i, count=0, left=additionalRocks;
        
        // how much is left of the bags that can be filled
        for(i=0; i<rocks.size(); i++)
            capacity[i]-=rocks[i];
        
        sort(capacity.begin(), capacity.end());
        i=0;
        
        while(i<capacity.size() && left>0)
        {
            if(capacity[i]==0)
            {
                count++;
                i++;
            }
            
            else if(left>=capacity[i])
            {
                count++;
                left-=capacity[i];
                i++;
            }
            
            else
                return count;
                
        }
        return count;

    }
};