// https://leetcode.com/problems/maximum-number-of-eaten-apples/
bool cmp_less(const pair<int, int> &l, const pair<int, int> &r){
    return l.first > r.first;
}

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        vector<pair<int, int>> heap;  // min heap, {end day, apples left}
        int count = 0, i;
        for(i = 0; i < apples.size(); i ++){
            if(apples[i] > 0){
                heap.push_back({i + days[i] - 1, apples[i]});
                push_heap(heap.begin(), heap.end(), cmp_less);
            }
            else if(heap.empty())
                continue;
                
            while(!heap.empty()){
                pair<int, int> e = heap.front();

                if(e.first < i){
                    pop_heap(heap.begin(), heap.end(), cmp_less);
                    heap.pop_back();
                }
                else{
                    count ++;
                    if(e.first == i || e.second == 1){
                        pop_heap(heap.begin(), heap.end(), cmp_less);
                        heap.pop_back();
                    }
                    else
                        heap.front().second --;
                    
                    break;
                }
            }
        }
        
        while(!heap.empty()){
            pair<int, int> e = heap.front();

            if(e.first < i){
                pop_heap(heap.begin(), heap.end(), cmp_less);
                heap.pop_back();
            }
            else{
                count ++;
                if(e.first == i || e.second == 1){
                    pop_heap(heap.begin(), heap.end(), cmp_less);
                    heap.pop_back();
                }
                else
                    heap.front().second --;
                i ++;
            }
        }
        return count;
    }

};
