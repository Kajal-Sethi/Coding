class Solution {
public:
    
    int solve(vector<int>& weights, int capacity)
    {
        int i, count=0, sum=0;
        for(i=0; i<weights.size(); i++)
        {
            if(sum+weights[i]<capacity)
                sum=sum+weights[i];
            
            else if(sum+weights[i]==capacity)
            {
                sum=0;
                count++;
            }
                
            else
            {
                // cout<<weights[i]<<" ";
                sum=weights[i];
                count++;
            }
        }
        
        if(sum!=0 && sum<capacity)
            count++;
        
        return count;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        // the weight of the ship should be atleast the wt of the max element
        // we will send atleast one package every day
        int minn=weights[0], sum=weights[0], i, mid, req;
        
        for(i=1; i<weights.size(); i++)
        {
            minn=max(minn, weights[i]);
            sum+=weights[i];
        }
        
        if(days==1)
            return sum;
        
        if(days>=weights.size())
            return minn;
     //   minn = max(minn, ceil(sum/weights.size()));
       
        // perform b.search btw sum and minn to get a capacity 
        // find the number of days for that capacity 
        while(minn<sum)
        {
            mid = (float(sum+minn)/2);
              cout<<mid<<" ";
           
            req = solve(weights, mid);
            cout<<req<<endl;
            
            if(req<=days)
                sum=mid;
            
            else 
                minn=mid+1;
        }
        
//         int prev=mid, use;
//         for(i=mid-1; i>=minn; i--)
//         {
//             use = solve(weights, i);
//             cout<<endl<<i<<" ye "<<use;
//             if(use==days || use==req)
//                 prev=i;
            
//             else
//                 return prev;
//         }        
        
        // cout<<" ppp ";
        //return prev;
        
        return minn;
    }
};