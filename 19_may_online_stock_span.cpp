class StockSpanner {
public:
    vector<int> v;
    vector<int> span;
    int l,n,prev;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        n = 1;
        l = v.size();
        v.push_back(price);
        if(l>0){
            if(v[l-1]==price){
                n = ++span[l - 1];
            }
            else if(v[l-1]<price){
                prev = l-1;
                while(prev>=0 && v[prev]<=price){
                    n += span[prev];
                    prev = l - n;
                }   
            }    
        }    
        span.push_back(n);
        return n;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
