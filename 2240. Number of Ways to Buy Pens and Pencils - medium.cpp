// https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        //cost1 * i + cost2 * j <= total
        long long ans = 0;
        for(int i = 0; i <= total; i += cost1)
            ans += 1 + (long long)(total - i) / cost2;

        return ans;
    }
};
