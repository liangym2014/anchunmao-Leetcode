// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i, n = chalk.size();

        long long sum = 0;
        for(auto &c: chalk)
            sum += c;

        k %= sum;
        for(i = 0; k >= chalk[i]; i ++){
            k -= chalk[i];
        }
        return i;
    }
};
