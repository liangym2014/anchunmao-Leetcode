//https://leetcode.com/problems/interleaving-string/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != (s1.size() + s2.size()))
            return false;
        
        if(s1.empty())  return s2 == s3;
        if(s2.empty())  return s1 == s3;
        
        s1 = " " + s1;
        s2 = " " + s2;
        
        vector<vector<bool>> inq(s1.size(), vector<bool>(s2.size())); // mark which combination is explored
        queue<pair<int, int>> q;
        
        if(s1[1] == s3[0]){
            q.push({1, 0});
            inq[1][0] = true;
        }
        
        if(s2[1] == s3[0]){
            q.push({0, 1});
            inq[0][1] = true;            
        }
        
        if(q.empty())
            return false;

        int k = 0;
        while((++ k) < s3.size()){
            int size = q.size();
            bool find = false;
            
            while(size){
                auto [i, j] = q.front();
                q.pop();

                if(i + 1 < s1.size() && !inq[i + 1][j] && s1[i + 1] == s3[k]){
                    q.push({i + 1, j});
                    find = true;
                    inq[i + 1][j] = true;
                }
              
                if(j + 1 < s2.size() && !inq[i][j + 1] && s2[j + 1] == s3[k]){
                    q.push({i, j + 1});
                    find = true;
                    inq[i][j + 1] = true;
                } 

                size --;
            }
            
            if(!find)
                return false;
        }
        return true;
    }
};
