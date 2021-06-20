// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0, i = 0, count = 0;
        string vowels("aeiou");
        
        for(i = 0; i < k; i ++){
            if(vowels.find(s[i]) != string::npos)
                count ++;
        }
        
        int ans = count;
        
        for(i = k; i < s.size(); i ++){
            if(vowels.find(s[l ++]) != string::npos)
                count --;
            
            if(vowels.find(s[i]) != string::npos){
                count ++;
                ans = max(ans, count);
            }
        }        
        return ans;
    }
};
