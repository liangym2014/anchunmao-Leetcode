//https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        vector<unordered_set<int>> startwords(26);
        
        for(auto &word: startWords){
            if(word.size() == 26)
                continue;
            
            startwords[word.size()].insert(generate_mask(word));
        }
        
        int ans = 0;
        
        for(auto &word: targetWords){
            int n = word.size();
            
            if(startwords[n - 1].empty())
                continue;
            
            int mask = generate_mask(word);
            
            unordered_set<int> *start_itr = &startwords[n - 1];
            for(auto &c: word){
                int bit = 1 << (c - 'a');
                bit = (~bit) & mask;
                if(start_itr->count(bit)){
                    ans ++;
                    break;
                }
            }
            
        }
        return ans;
    }
    
    int generate_mask(string &word){
        int mask = 0;
        for(auto &c: word)
            mask |= 1 <<(c - 'a');
        return mask;
    }

};
