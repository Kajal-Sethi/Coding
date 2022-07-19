class StockSpanner {
public:
    
    stack<pair<int,int>> st;
    vector<int> arr;
    
    StockSpanner() {   
        arr.clear();
    }
        
    int next(int price) {
        
        int ret;
        // value , index
        arr.push_back(price);
        
        while(!st.empty() && st.top().first<=arr[arr.size()-1])
            st.pop();
            
        if(st.empty())
            ret = arr.size();
            
        else
            ret = arr.size()-1-st.top().second;
            
        st.push({arr[arr.size()-1], arr.size()-1});
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */