/*
https://leetcode.com/problems/short-encoding-of-words/
*/

#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool cmp(const string& l, const string& r){
    return l.size() > r.size();
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        vector<vector<string>> first_letter(26);
        sort(words.begin(), words.end(), cmp);
        
        for(auto& word: words){
            reverse(word.begin(), word.end());
            int idx = word[0] - 97;

            bool prefix = false;
            for(auto& str: first_letter[idx]){
                if(str.find(word) == 0){
                    prefix = true;
                    break;
                }
            }
            
            if(prefix)    continue;
            first_letter[idx].push_back(word);
        }
        
        int ans = 0;
        for(int i = 0; i < 26; ++ i){
            for(auto& str: first_letter[i])
                ans += str.size() + 1;
        }
        return ans;
    }
};
