// https://leetcode.com/problems/split-two-strings-to-make-palindrome/
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return helper(a, b) || helper(b, a);
    }
    
    bool helper(string &a, string &b){
        int i = 0, j = a.size() - 1;        
        auto [l1, r1] = checkstrs(a, a, i, j);
        if(l1 >= r1) return true;
        
        auto [l2, r2] = checkstrs(a, b, i, j);
        if(l2 >= r2) return true;
        
        auto [l3, r3] = checkstrs(a, a, l2, r2);
        if(l3 >= r3) return true; 
        
        auto [l4, r4] = checkstrs(b, b, l2, r2);
        if(l4 >= r4) return true;
        
        return false;
    }
    
    pair<int, int> checkstrs(string &a, string &b, int i, int j){
        while(i < j && a[i] == b[j]){
            ++ i;
            -- j;
        }        
        return {i, j};
    }
};
