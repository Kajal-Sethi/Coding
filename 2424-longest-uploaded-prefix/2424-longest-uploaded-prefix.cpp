class LUPrefix {
public:
    
    map<int, int>mp;
    int cont=0;
    
    LUPrefix(int n) {
        // size=n;
    }
    
    void upload(int video) {
        mp[video]++;
        while(mp.find(cont+1)!=mp.end())
            cont++;
    }
    
    int longest() {
        return cont;   
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */