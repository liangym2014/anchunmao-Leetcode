// https://leetcode.com/problems/detonate-the-maximum-bombs/
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> trigger(n);
        
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                int res = range(bombs[i], bombs[j]);
                
                if(!res)
                    continue;
                
                if(res == 1)
                    trigger[i].push_back(j);
                else if(res == 2)
                    trigger[j].push_back(i);
                else{
                    trigger[i].push_back(j);
                    trigger[j].push_back(i);                    
                }
            }
        }
        
        vector<bool> detonation(n);
        int ans = 0;
        for(int i = 0; i < n; i ++){
            if(trigger[i].empty()){
                ans = max(ans, 1);
                continue;
            }
            
            detonation.assign(n, false);
            vector<int> cur({i});
            detonation[i] = true;
            int acc = 1;
            
            while(!cur.empty()){
                vector<int> frontier;
                
                for(auto &bomb: cur){
                    for(auto &new_bomb: trigger[bomb]){
                        if(detonation[new_bomb])
                            continue;

                        detonation[new_bomb] = true;
                        acc ++;
                        frontier.push_back(new_bomb);
                    }
                }
                cur = frontier;
            }

            ans = max(ans, acc);
        }
        return ans;
    }
    
    inline int range(const vector<int> &b1, const vector<int> &b2){
        int x1 = b1[0], y1 = b1[1], r1 = b1[2],
            x2 = b2[0], y2 = b2[1], r2 = b2[2];
        
        double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) * 1.0);

        if(d <= r1 && d <= r2) // both can denonate each other
            return 3;
        
        if(d <= r1)  // bomb2 in the range of bomb1
            return 1;
        
        if(d <= r2) // bomb1 in the range of bomb2
            return 2;
        
        return 0; // bomb1 and bomb2 no overlap
    }
};
