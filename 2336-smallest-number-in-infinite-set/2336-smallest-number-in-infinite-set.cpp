class SmallestInfiniteSet {
public:
    
    // map<int,int> val;
    set<int> val;
    SmallestInfiniteSet() {
        // initialization
        
        for(int i=1; i<=1000; i++)
            // val[i]=1;   
        val.insert(i);
    }
    
    int popSmallest() {
        int minn=INT_MAX;
        for(auto i:val)
            minn=min(minn, i);
        // returns the smallest num and removes it from obj
//         map<int,int> :: iterator i = val.begin();
        
//             // map<int, int>::iterator itr; 
//         val.erase(i);
//         return i->first;        
        
        val.erase(minn);
        return minn;
    }
    
    void addBack(int num) {
        // add num back into infinite set, iff it is not there.
        // val[num]=1;
        val.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */