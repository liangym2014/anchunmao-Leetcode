// https://leetcode.com/problems/stock-price-fluctuation/
bool cmp_less(const pair<int, int> &l, const pair<int, int> &r){
    return l.first > r.first;
}

bool cmp_greater(const pair<int, int> &l, const pair<int, int> &r){
    return l.first < r.first;
}

class StockPrice {
private:
    unordered_map<int, int> prices; // key: time, value: price
    int latest_time = -1, latest_price = 0;
    vector<pair<int, int>> minheap, maxheap; // {price, timestamp}
    
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        prices[timestamp] = price;

        if(timestamp >= latest_time){
            latest_time = timestamp;
            latest_price = price;
        }
        
        minheap.push_back({price, timestamp});
        push_heap(minheap.begin(), minheap.end(), cmp_less);
        
        maxheap.push_back({price, timestamp});
        push_heap(maxheap.begin(), maxheap.end(), cmp_greater);
    }
    
    int current() {
        return latest_price;
    }
    
    int maximum() {
        while(!maxheap.empty()){
            pair<int, int> mx = maxheap.front();
            if(prices[mx.second] == mx.first)
                return mx.first;
            
            pop_heap(maxheap.begin(), maxheap.end(), cmp_greater);
            maxheap.pop_back();
        }
        return 0;
    }
    
    int minimum() {
        while(!minheap.empty()){
            pair<int, int> mn = minheap.front();
            if(prices[mn.second] == mn.first)
                return mn.first;
            
            pop_heap(minheap.begin(), minheap.end(), cmp_less);
            minheap.pop_back();
        }
        return 0;
    }
};
