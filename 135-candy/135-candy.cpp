class Solution {
public:
    int candy(vector<int>& rate) {
        vector<int> left(rate.size(),1), right(rate.size(),1);
        int i, need=0;
        
        for(i=1; i<rate.size(); i++)
            if(rate[i]>rate[i-1])
                left[i] = left[i-1]+1;
        
        for(i=rate.size()-2; i>=0; i--)
            if(rate[i]>rate[i+1])
                right[i] = right[i+1]+1;
        
        for(i=0; i<rate.size(); i++)
            need = need+max(left[i], right[i]);
        
        return need;
    }
};