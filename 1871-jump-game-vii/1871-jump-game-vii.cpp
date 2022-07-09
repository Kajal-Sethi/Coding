class Solution {
public:
    
    bool canReach(string s, int minJump, int maxJump) {

        // index, val
        queue<int> q;
        int t[s.size()], i, j, processed=0;
        
        // memset(t, 0, sizeof(t));
        // t[0] = true;
        
        q.push(0);
        while(!q.empty())
        {
            j=q.front();
            q.pop();
            int range = s.size()-1 < j+maxJump?s.size()-1: j+maxJump;
            int start = max(j+minJump, processed);
            
            for(i= start; i<=range; i++)
            {
                if(s[i]=='0')
                {    
                    // t[i]=true;
                    q.push(i);
                }    
                
                if(i==s.size()-1 && s[s.size()-1]=='0')
                    return true;
            }
            
            processed = range+1;
        }
        
        return false;
        // return t[s.size()-1];
    }
};