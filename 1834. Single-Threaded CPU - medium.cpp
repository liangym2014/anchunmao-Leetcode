// https://leetcode.com/problems/single-threaded-cpu/

bool cmp1(const vector<int>& l, const vector<int>& r){
    return l.front() < r.front();
}

bool cmp2(const pair<int, int>& l, const pair<int, int>& r){
    return (l.first > r.first)? true: (l.first == r.first? (l.second > r.second): false);
}

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); i ++)
            tasks[i].push_back(i);
        
        sort(tasks.begin(), tasks.end(), cmp1); // sort by enqueue time in ascending order
        
        vector<pair<int, int>> h; // min heap, first: processing time, second: index

        vector<int> ans;
        int i = 0;
        long long time = 0;  //current time
        
        while(i < tasks.size()){
            // if no more tasks in the heap, move timeline to the next enqueue time
            if(h.empty() && i < tasks.size() && tasks[i][0] > time)
                time = tasks[i][0];
            
            // put all tasks before current time into the heap
            while(i < tasks.size() && tasks[i][0] <= time){
                h.push_back({tasks[i][1], tasks[i][2]});
                push_heap(h.begin(), h.end(), cmp2);
                i ++;
            }

            pair<int, int> f = h.front();
            pop_heap(h.begin(), h.end(), cmp2);
            h.pop_back();

            time += (long long)f.first;
            ans.push_back(f.second);

        }

        while(!h.empty()){
            pair<int, int> f = h.front();
            pop_heap(h.begin(), h.end(), cmp2);
            h.pop_back();
            ans.push_back(f.second);            
        }
        
        return ans;
    }
};
