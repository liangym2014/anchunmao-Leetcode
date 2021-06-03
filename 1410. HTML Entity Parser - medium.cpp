// https://leetcode.com/problems/html-entity-parser/

class Solution {
public:
    string entityParser(string text) {
        vector<pair<string, string>> special_chars{{"&quot;", "\""},{"&apos;", "\'"}, {"&amp;", "&"},
                                                    {"&gt;", ">"}, {"&lt;", "<"}, {"&frasl;", "/"}};
        string res;
        int start = 0;
        size_t max_pos = 100000;
      
        while(1){
            size_t pos = max_pos;
            int idx = -1;
            
            for(int i = 0; i < special_chars.size(); ++ i){
                size_t p = text.find(special_chars[i].first, start);
                
                if(p == string::npos){
                    continue;
                }

                if(pos > p){
                    pos = p;
                    idx = i;
                }
            }

            if(idx < 0){
                res += text.substr(start);
                break;
            }
            else{
                res += text.substr(start, pos - start) + special_chars[idx].second;
                start = pos + special_chars[idx].first.size();
            }
        }

        return res;
    }
};
