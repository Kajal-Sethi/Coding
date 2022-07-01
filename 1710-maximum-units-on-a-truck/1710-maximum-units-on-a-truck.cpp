class Solution {
public:
    
    static bool col(vector<int> row1, vector<int> row2)
    {
        return row1[1]>row2[1];
    }
        
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // maximize the units
        // greedy 
        
        sort(boxTypes.begin(), boxTypes.end(), col);
        int index=0, left = truckSize, units=0;
        while(index<boxTypes.size() && left>0)
        {
            if(boxTypes[index][0]<=left)
            {
                units+=boxTypes[index][1]*boxTypes[index][0];
                left-=boxTypes[index][0];
                index++;
            }
            
            else
            {
                units+=boxTypes[index][1]*(left);
                break;
            }
        }
        
        return units;
    }
};