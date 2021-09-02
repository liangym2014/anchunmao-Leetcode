// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        if(s.size() < part.size())
            return s;
        
        size_t pos = s.find(part);
        while(pos != string::npos){
            s.erase(pos, part.size());
            pos = s.find(part);
        }
        return s;
    }
};
