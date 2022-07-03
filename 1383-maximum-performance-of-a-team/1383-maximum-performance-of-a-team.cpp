class Solution {
public:
    
    static bool lastval(pair<int, int> a, pair<int, int> b)
    {
        return a.second>b.second;
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // performance = sum of speeds * minimum efficiency
        int i, j, req;
        
        // speed, eff
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<pair<int, int>>here;
        pair<int, int>use;
        
        for(i=0; i<n; i++)
        {
            use.second = efficiency[i];
            use.first = speed[i];
            here.push_back(use);
        }
        // speed, eff. sorted acc to eff
        sort(here.begin(), here.end(), lastval);
        
        long long sum=0, maxx=0, val=0;
        // int i, j, val=0, req;
        
        // use heap for speed
        i=0;
        while(pq.size()<k)
        {
            pq.push(here[i]);
            sum+=here[i].first;
            val = sum*here[i].second;
            i++;
      //      cout<<val<<" ";
            maxx = max(maxx, val);
        }
        
      //  maxx=sum*here[i-1].second;
        
        for(; i<n; i++)
        {
            use=pq.top();
            pq.pop();
            pq.push(here[i]);
            sum-=use.first;
            sum+=here[i].first;
            
            val = sum*here[i].second;
            maxx=max(maxx, val);
        }

        return maxx%1000000007;
    }
};