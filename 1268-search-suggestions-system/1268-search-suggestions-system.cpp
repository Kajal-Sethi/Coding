struct trie{
    trie* character[26];
    bool isLeaf;
    
    trie()
    {
        for(int i=0; i<26; i++)
            character[i]=NULL;
        
        isLeaf=false;
    }
};
    
class Solution {
public:
    trie *root;
    Solution()
    {
        root = new trie();
    }
    
    void insert(string str)
    {
        trie *node = root;
        for(int i=0; i<str.size(); i++)
        {
            if(!node->character[str[i]-'a'])
                node->character[str[i]-'a'] = new trie();
            
            node = node->character[str[i]-'a'];
        }
        node->isLeaf=true;
    }
        
    void dfs(trie* node, vector<string> &res, string prefix)
    {
        if(res.size()==3)
            return;
        
        if(node->isLeaf==true)
            res.push_back(prefix);
        
        // trie* tempnode;
        for(int i=0; i<26; i++)
        {
            if(node->character[i])
            {
                prefix.push_back(i+'a');
                // node = node->character[i];
                dfs(node->character[i], res, prefix);
                prefix.pop_back();
            }
        }
    }
    
    void search(string prefix, vector<string> &res)
    {
        trie *node = root;
        for(int i=0; i<prefix.size();i++)
        {
            if(!node->character[prefix[i]-'a'])
                return;
            
            node = node->character[prefix[i]-'a'];
        }
        
        // if(node->isLeaf=true)
        //     res.push_back(prefix);
        
        dfs(node, res, prefix);
    }
        
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for(int i=0; i<products.size(); i++)
            insert(products[i]);
    
        vector<vector<string>> ans;
        string prefix;
        for(int i=0; i<searchWord.size(); i++)
        {
            vector<string> res;
            prefix.push_back(searchWord[i]);
            search(prefix, res);
            ans.push_back(res);
        }
        
        return ans;
    }
};