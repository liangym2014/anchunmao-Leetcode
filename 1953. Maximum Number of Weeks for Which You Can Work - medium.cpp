// https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int mx = *max_element(milestones.begin(), milestones.end());
        long long sum = accumulate(milestones.begin(), milestones.end(), (long long) 0);
        return mx > (sum - mx + 1)? ((sum - mx) * 2 + 1): sum;
    }
};
