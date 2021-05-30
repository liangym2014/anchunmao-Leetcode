// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

#include <vector>
#include <algorithm>

class Solution {
public:
    int findTheLongestSubstring(string s) {
        // current uses the lowest 5 bits to record the number of each vowel.
        // when the number of the vowel is odd, set the bit to 1. when it's even, set the bit to 0.
        int current = 0, ans = 0;

        // the first occurrence of status i, i = 0 ~ 31. 
        // if i = 0: start[0] = -1.
        // if i > 0: if start[i] < 0, undefined. otherwise start[i] is the first occurrence of status i.
        vector<int> start(32, -1);
        
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == 'a')
                current ^= (1 << 4);
            else if(s[i] == 'e')
                current ^= (1 << 3);
            else if(s[i] == 'i')
                current ^= (1 << 2);
            else if(s[i] == 'o')
                current ^= (1 << 1);
            else if(s[i] == 'u')
                current ^= 1;

            if(current == 0 || start[current] >= 0)
                ans = max(ans, i - start[current]);
            else
                start[current] = i;
        }

        return ans;
    }

};
