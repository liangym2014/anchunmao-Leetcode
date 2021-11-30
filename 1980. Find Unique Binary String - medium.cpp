// https://leetcode.com/problems/find-unique-binary-string/
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        set<string> strings(nums.begin(), nums.end());
        
        string ans = string(n, '1');
        while(strings.count(ans)){
            int idx = rand() % n;
            ans[idx] = '0' + '1' - ans[idx];
        }
        return ans;
    }
};
