class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int i, maxx=0, diff;
        
        sort(special.begin(), special.end());
        diff = special[0]-bottom;
        
        for(i=1; i<special.size(); i++)
        {
            maxx=max(maxx, diff);
            diff = special[i]-(special[i-1]+1);            
        }
        
        maxx=max(maxx, diff);
        diff = top-special[i-1]; 
        return max(maxx, diff);
    }
};