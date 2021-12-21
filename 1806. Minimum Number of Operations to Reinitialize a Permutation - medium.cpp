// https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
class Solution {
public:
    int reinitializePermutation(int n) {
        if(n == 2)  return 1;
        
        int original = 2, cur = 2, ops = 0;
        
        do{
            int i = cur * 2;
            if(i < n)
                cur = i;
            else
                cur = i - n + 1;
            ops ++;

        }while(original != cur);
        
        return ops;
    }
};
