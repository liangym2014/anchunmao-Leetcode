//https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int min_dist = cards.size() + 1;
        unordered_map<int, int> m;
        for(int i = 0; i < cards.size(); i ++){
            int num = cards[i];
            if(m.count(num) && ((i - m[num] + 1) < min_dist))
                min_dist = i - m[num] + 1;
            m[num] = i;
        }
        return min_dist > cards.size()? (-1): min_dist;
    }
};
