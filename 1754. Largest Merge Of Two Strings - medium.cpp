// https://leetcode.com/problems/largest-merge-of-two-strings/
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans(word1.size() + word2.size(), ' ');
        int i = 0, j = 0, k = 0;
        
        while(i < word1.size() && j < word2.size()){
            if(word1[i] < word2[j])
                ans[k ++] = word2[j ++];
            else if(word1[i] > word2[j])
                ans[k ++] = word1[i ++];
            else{
                bool is_word1_smaller = lexicographical_compare(word1.begin() + i, word1.end(),
                                                   word2.begin() + j, word2.end());
                
                if(is_word1_smaller){// take word2
                    ans[k ++] = word2[j ++];
                    while(j < word2.size() && word2[j] == word2[j - 1])
                        ans[k ++] = word2[j ++];                    
                }
                else{// take word1
                    ans[k ++] = word1[i ++];
                    while(i < word1.size() && word1[i] == word1[i - 1])
                        ans[k ++] = word1[i ++];                    
                }
              
            }

        }
        
        if(i < word1.size())
            ans.replace(ans.begin() + k, ans.end(), word1.begin() + i, word1.end());
        else if(j < word2.size())
            ans.replace(ans.begin() + k, ans.end(), word2.begin() + j, word2.end());
        
        return ans;
    }
};
