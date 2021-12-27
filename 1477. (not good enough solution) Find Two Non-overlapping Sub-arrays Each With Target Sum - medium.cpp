// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<pair<int, int>> v; //{end index of the subarray, minimum length of subarray}
        int min_sum_len = INT_MAX;
        if(arr[0] == target)
            v.push_back({0, 1});
        
        for(int i = 1; i < arr.size(); ++ i){
            arr[i] += arr[i - 1];
            
            if(arr[i] < target)
                continue;
            
            int prev = arr[i] - target;
            int length = -1, start = 0; //length and start index of qualified subarray, length < 0 is invalid
            
            if(!prev)
                length = i + 1;
            else{
                auto it = lower_bound(arr.begin(), arr.begin() + i, prev);
                if(*it == prev){
                    start = it - arr.begin() + 1;
                    length = i - start + 1;
                }
            }

            if(length < 0)
                continue;

            if(v.empty()){
                v.push_back({i, length});
            }
            else if(length < min_sum_len){
                auto it = lower_bound(v.begin(), v.end(), start, 
                            [](const pair<int, int> &l, const int &val){return l.first < val;});

                if(it != v.begin()){
                    min_sum_len = min((-- it)->second + length, min_sum_len);
                    if(min_sum_len == 2) return min_sum_len;
                }
                v.push_back({i, min(length, v.back().second)});
            }
        }
        return min_sum_len < INT_MAX? min_sum_len: (-1);
    }
};
