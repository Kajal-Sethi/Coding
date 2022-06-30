class Solution {
public:
    
    vector<int> med;
    int partition(vector<int>& nums, int l, int h)
    {
        int num = l + rand()%(h-l+1);
        swap(nums[h], nums[num]);
        int i=l-1,j,pi=h;
        for(j=l; j<h; j++)
        {
            if(nums[j]<nums[pi])
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        i++;
        swap(nums[i], nums[pi]);
        return i;
    }
    
    void quick(vector<int>& nums, int l, int h, int find)
    {
        if(l<=h)
        {
            int pi = partition(nums, l, h);
            
            if(pi==find)
            {
                med.push_back(nums[pi]);
                return;
            }
            
            if(pi>find)
                quick(nums, l, pi-1, find);
            
            else
                quick(nums, pi+1, h, find);
        }
    }
    
    
    int minMoves2(vector<int>& nums) {
        // shift to the median of the array
        int i, median, count=0, n=nums.size();
        if(n==1||n==0)
            return 0;
        
        med.clear();
        quick(nums, 0, n-1, n/2);
        if(n%2==0)
        {
            quick(nums, 0, n-1, n/2-1);
            median = ceil(float(med[0] + med[1])/2);
        }    
        
        else
           median = med[0];
        
        for(i=0; i<nums.size(); i++)
            count+=abs(median-nums[i]);
        
        return count;
    }
};