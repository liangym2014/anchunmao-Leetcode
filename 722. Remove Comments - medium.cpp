// https://leetcode.com/problems/remove-comments/submissions/
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool in_block = false;
        string single_line;
        
        for(auto &s: source){
            if(in_block){
                size_t block = s.find("*/");
                if(block == string::npos)  continue;
                s = s.substr(block + 2);
                in_block = false;
            }
            else
                single_line.clear();
            
            size_t line = s.find("//"), block = s.find("/*");
            
            while(!in_block){
                if(line == string::npos && block == string::npos){
                    single_line += s;
                    break;
                }

                if(block < line){
                    single_line += s.substr(0, block);

                    block = s.find("*/", block + 2);
                    if(block == string::npos){
                        in_block = true;
                        break;
                    }
                    
                    s = s.substr(block + 2);
                    line = s.find("//");
                    block = s.find("/*");
                }
                else{ // line < block
                    single_line += s.substr(0, line);
                    break;
                }
            }
            
            if(!in_block && !single_line.empty())
                ans.push_back(single_line);
        }
        return ans;
    }
};
