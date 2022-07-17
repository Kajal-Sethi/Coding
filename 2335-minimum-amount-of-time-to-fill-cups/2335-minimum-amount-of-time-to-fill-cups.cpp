class Solution {
public:
    int fillCups(vector<int>& amount) {
        int count=0, maxx, maxx2;
        priority_queue<int> pq;
        
        if(amount[0]>0)
            pq.push(amount[0]);
        
        if(amount[1]>0)
            pq.push(amount[1]);
        
        if(amount[2]>0)
            pq.push(amount[2]);
        
        while(!pq.empty())
        {
            maxx = pq.top();
            pq.pop();
            
            if(!pq.empty())
            {
                maxx2 = pq.top();
                pq.pop();
                
                count++;
                
                maxx--;
                maxx2--;
                
                if(maxx>0)
                    pq.push(maxx);
                
                if(maxx2>0)
                    pq.push(maxx2);
            }
            
            else
                count+=maxx;
        }
        
        return count;
    }
};