// https://leetcode.com/problems/range-frequency-queries/
class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> m; //key: number in arr, value: the indices of this value in arr
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i ++)
            m[arr[i]].push_back(i);
        
    }
    
    int query(int left, int right, int value) {
        if(m.find(value) == m.end())
            return 0;
        
        vector<int> *v = &m[value];
        int i = lower_bound(v->begin(), v->end(), left) - v->begin();
        int j = upper_bound(v->begin(), v->end(), right) - v->begin();
        
        return j - i;
    }
};
