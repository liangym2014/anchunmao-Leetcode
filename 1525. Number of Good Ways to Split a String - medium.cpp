//https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

class Solution {
public:
    int numSplits(string s) {
        int ans = 0;
        unordered_set<char> chrs;
        vector<int> lscan;  // the number of distinct letters while scanning s from left to right
        
        for(auto &c: s){
            chrs.insert(c);
            lscan.push_back(chrs.size());
        }
        
        chrs.clear();
        for(int i = s.size() - 1; i && (lscan[i - 1] >= chrs.size()); i --){
            chrs.insert(s[i]);
            if(lscan[i - 1] == chrs.size())
                ans ++;
        }
        
        return ans;
    }
};
