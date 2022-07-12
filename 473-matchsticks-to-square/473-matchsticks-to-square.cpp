class Solution {
public:
    
    // int t[15][4];
    bool solve(int left[], vector<int> &arr, int index)
    {
        if(index>=arr.size())
            return(left[0]==0 && left[1]==0 && left[2]==0 && left[3]==0);

        for(int i=0; i<4; i++)
        {
            if(left[i]>=arr[index])
            {
                left[i]-=arr[index];
                if(solve(left, arr, index+1))
                    return true;
                
                left[i]+=arr[index];
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& arr) {
        // add up the array. and find sum/4 in the array   
        
        int i, sum=0;
        for(i=0; i<arr.size(); i++)
            sum+=arr[i];
        
        if(sum%4!=0)
            return false;
        // we know we have 4 boxes and max capacity of each box is sum/4
        int left[4]={sum/4, sum/4, sum/4, sum/4};
        
        // cout<<left[0]<<left[1]<< left[2]<<left[3];
        sort(arr.rbegin(), arr.rend());
        // cout<<sum/4<<endl;
        return solve(left, arr, 0);
        
    }
};