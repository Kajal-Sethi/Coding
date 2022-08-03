class MyCalendar {
public:
    map<int, int> store;
    
    bool good(int start, int end)
    {
        if(store.empty())
            return true;
        
        auto up = store.upper_bound(start);
        
        // if(up==store.end())
        //     return true;
        
        if(((*up).first>start && (*up).first<end) || ((*up).second>start && (*up).second<end))
            return false;
        
        if((*up).first>=start && (*up).first>=end && (*up).second<=start && (*up).second<=end)
            return false;
        
        return true;
        
    }
        
    MyCalendar() {
        store.clear();
    }
    
    bool book(int start, int end) {
        
        if(good(start, end))
        {
            store[end] = start;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */