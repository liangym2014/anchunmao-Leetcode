// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/submissions/
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        // cout<<nums.size();
        k = nums.size() - k + 1;  // the goal is modified to find the kth smallest element
        map<int, vector<int>> strlen;  // assign indices of elements in nums according to their length
        
        for(int i = 0; i < nums.size(); i ++)
            strlen[nums[i].size()].push_back(i);
        
        int n = 0, idx = -1;
        
        for(auto &e: strlen){
            n += e.second.size();
            if(n >= k){
                idx = e.first;
                n = e.second.size() - (n - k);
                break;
            }
        }
        
        // only address the elements in strlen[idx], find the nth smallest element among those with the length of idx
        map<string, int> counter;
        for(auto& i: strlen[idx]){
            counter[nums[i]] ++;
        }
        
        int acc = 0;
        for(auto &e: counter){
            acc += e.second;
            if(acc >= n)
                return e.first;
        }
        return "-1";
    }

};
