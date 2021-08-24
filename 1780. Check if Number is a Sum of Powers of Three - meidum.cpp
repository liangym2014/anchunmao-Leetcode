// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
class Solution {
private:
    static vector<int> nums;
public:
    bool checkPowersOfThree(int n) {
        if(nums.size() == 1){
            while(nums.back() <= 1e7)
                nums.push_back(nums.back() * 3);
        }
        
        unordered_set<int> used;
        while(n){
            auto itr = upper_bound(nums.begin(), nums.end(), n);
            int power = *(-- itr);
            if(used.count(power))
                return false;

            n -= power;
            used.insert(power);
        }
        return true;
    }
};

vector<int> Solution::nums = {1};
