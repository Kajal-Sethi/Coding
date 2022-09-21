struct trie{
    trie* num[10];
    bool isend;
    int number;
    
    trie(){
        for(int i=0; i<=9; i++)
            num[i]=NULL;
    
        number = 0;
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
        string str = to_string(n);
        trie *node = root;
        
        for(int i=0; i<str.size(); i++)
        {
            if(!node->num[str[i]-'0'])
                node->num[str[i]-'0'] = new trie();
            
            node = node->num[str[i]-'0'];
        }
        node->number = n;
        node->isend = true;
    }
        
    void sortt(trie *node, vector<int> &ans)
    {
        if(node->isend)
            ans.push_back(node->number);
        
        for(int i=0; i<=9; i++)
            if(node->num[i])
                sortt(node->num[i], ans);
    }
        
    vector<int> lexicalOrder(int n) {
        for(int i=1; i<=n; i++)
            insert(i);
        
        vector<int> ans;
        sortt(root, ans);
        
        return ans;
    }
};