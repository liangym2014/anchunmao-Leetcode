// https://leetcode.com/problems/making-file-names-unique/
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> used_names;
        for(auto &name: names){
            if(used_names.count(name)){
                int suffix = used_names[name];
                while(used_names.count(name + '(' + to_string(suffix) + ')'))
                    suffix ++;
                
                used_names[name] = 1 + suffix;                
                name += '(' + to_string(suffix) + ')';
            }

            used_names[name] = 1;
        }
        return names;
    }
};
