struct Node{
    struct Node* links[26];
    bool isend;
};

class Trie {
public:
    struct Node* root;
    
    struct Node* new_node(struct Node* node)  
  {
        node = (struct Node*)malloc(sizeof(struct Node));
        for(int i=0; i<26; i++)
            node->links[i]=NULL;
        
        node->isend=false;
      return node;
  }
    Trie() {
        root = new_node(root);
    }
    
    void insert(string word) {
        Node* node = root;
        
        for(int i=0; i<word.size(); i++)
        {
            cout<<word[i]-'a'<<" ";
            if(node->links[word[i]-'a']==NULL)
                node->links[word[i]-'a'] = new_node(new struct Node);
            
            node = node->links[word[i]-'a'];
        }
        
        node->isend=true;
    }
    
    bool search(string word) {
        Node* node = root;
        
        for(int i=0; i<word.size(); i++)
        {
            if(node->links[word[i]-'a']==NULL)
                return 0;
            
            node = node->links[word[i]-'a'];
        }
        
        return node->isend;
    }
    
    bool startsWith(string word) {
        Node* node = root;
        
        for(int i=0; i<word.size(); i++)
        {
            if(node->links[word[i]-'a']==NULL)
                return 0;
            
            node = node->links[word[i]-'a'];
        }
        
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */