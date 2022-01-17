// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
int mod = 1e9 + 7;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        int max_height = horizontalCuts[0];
        for(int i = 1; i < horizontalCuts.size(); ++ i)
            max_height = max(max_height, horizontalCuts[i] - horizontalCuts[i - 1]);
        
        max_height = max(max_height, h - horizontalCuts.back());
        
        sort(verticalCuts.begin(), verticalCuts.end());
        int max_width = verticalCuts[0];
        for(int i = 1; i < verticalCuts.size(); ++ i)
            max_width = max(max_width, verticalCuts[i] - verticalCuts[i - 1]);
        
        max_width = max(max_width, w - verticalCuts.back());
        
        return (long long) (max_height % mod) * (max_width % mod) % mod;
    }
};
