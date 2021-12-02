// https://leetcode.com/problems/maximum-compatibility-score-sum/submissions/

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        char mask = 0;
        unordered_map<char, int> m;
        m[0] = 0;
        
        
        for(int i = 0; i < students.size(); i ++){
            unordered_map<char, int> newmap;
            
            for(auto &e: m){
                char key = e.first;
                
                for(int j = 0; j < mentors.size(); j ++){
                    if((key >> j) & 1)
                        continue;
                    char newkey = key | (1 << j);
                    newmap[newkey] = max(newmap[newkey], e.second + compute_score(students[i], mentors[j]));
                }
            }
            
            m = newmap;
        }
        return m.begin()->second;
    }
    
    int compute_score(const vector<int> &student, const vector<int> mentor){
        int acc = 0;
        for(int i = 0; i < student.size(); i ++){
            if(student[i] == mentor[i])
                acc ++;
        }
        return acc;
    }
};
