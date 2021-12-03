// https://leetcode.com/problems/vowels-of-all-substrings/
class Solution {
public:
    long long countVowels(string word) {
        // acc: the sum of the number of vowels in substrings that ending with word[i] in word[0: i]
        long long ans = 0, acc = 0;
        for(int i = 0; i < word.size(); i ++){
            // the character word[i+1], if it's a vowel, it will add 1 vowel to all substrings ending with
            // word[i] in word[0:i], plus the number of vowels in substring word[i+1:i+1] 
            acc += isVowel(word[i]) * (i + 1);
            // ans is the sum of acc of all word[0:i]
            ans += acc;
        }
        return ans;
    }
    
    inline bool isVowel(char &c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};
