// https://leetcode.com/problems/maximum-ice-cream-bars/
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int i = 0;
        while(i < costs.size() && coins >= costs[i]){
            coins -= costs[i ++];
        }

        return i;
    }
};
