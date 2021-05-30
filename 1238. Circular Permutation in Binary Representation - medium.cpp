// https://leetcode.com/problems/circular-permutation-in-binary-representation/

#include <vector>

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int len = pow(2, n);        
        vector<int> ans{start}, visited(len, 0);
        visited[start] = 1;
        
        while(ans.size() < len){
            for(int i = 0; i < n; ++ i){
                if(visited[start ^ (1 << i)] == 0){
                    start ^= (1 << i);
                    ans.push_back(start);
                    visited[start] = 1;
                    break;
                }
            }
        }
        
        return ans;
    }
};
