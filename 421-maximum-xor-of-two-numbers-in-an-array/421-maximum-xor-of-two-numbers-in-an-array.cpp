struct trie{
    trie* num[2];
    bool isend;
    
    trie(){
        for(int i=0; i<2; i++)
            num[i]=NULL;
    
        isend=false;
    }
};

class Solution {
public:
    trie *root;
    
    Solution()
    {
        root = new trie();
    }
    
    void insert(int n)
    {
        trie *node = root;
        
        for(int i=31; i>=0; i--)
        {
            int bit = n>>i;
            bit = bit&1;
            // cout<<bit<<" ";
            if(!node->num[bit])
                node->num[bit] = new trie();
            
            node = node->num[bit];
        }
        // node->number = n;
        node->isend = true;
    }
        
    int solve(int n)
    {
        int ans = 0;
        trie *node = root;
        
        for(int i=31; i>=0; i--)
        {
            int bit = n>>i;
            bit = bit&1;
            // if opposite to this exist then set this bit in ans
            if(node->num[1-bit])
            {
                ans = ans|1<<i;
                node = node->num[1-bit];
            }
            
            else
                node = node->num[bit];
        }
        
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
            insert(nums[i]);
        
        int maxx=INT_MIN;
        for(int i=0; i<nums.size(); i++)
            maxx = max(maxx, solve(nums[i]));
        
        return maxx;
    }
};