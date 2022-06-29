class Solution {
public:
    
    int totalHammingDistance(vector<int>& nums) {
        vector<vector<int>> bits;
        int i, j;
        
        for(i=0; i<nums.size(); i++)
        {   
            vector<int> temp;
            while(nums[i]>0)
            {
                temp.push_back(nums[i]&1);
                nums[i]/=2;
            }
            // select end 32 bits and save them to the array bits
            reverse(temp.begin(), temp.end());            
            int siz = temp.size();

            while(siz<32)
            {
                temp.insert(temp.begin(),0);
                siz++;
            }
            
            bits.push_back(temp);
        }
        
        int count=0, res=0;
        for(i=0; i<32; i++)
        {
            int n1=0, n0=0;
            for(j=0; j<bits.size(); j++)
            {
                if(bits[j][i]==0)
                    n0++;
                
                else
                    n1++;
                
            }
            count+=n1*n0;
            
        }
        
        return count;
    }
};