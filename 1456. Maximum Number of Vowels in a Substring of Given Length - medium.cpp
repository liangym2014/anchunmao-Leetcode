// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0, i = 0, count = 0;
        
        for(i = 0; i < k; i ++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                count ++;
        }
        
        int ans = count;
        
        for(i = k; i < s.size(); i ++, l ++){
            if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u')
                count --;
            
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                count ++;
                ans = max(ans, count);
            }
        }        
        return ans;
    }
};
