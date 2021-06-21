// https://leetcode.com/problems/count-unhappy-friends/

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        unordered_set<int> unhappy;  // unhappy friends
        vector<int> partner(n);   // the partner for ith(i = 0 ~ n - 1) person in pairs
        
        for(auto &pair: pairs){
            partner[pair[0]] = pair[1];
            partner[pair[1]] = pair[0];
        }
        
        for(auto &pair: pairs){
            int x = pair[0], y = pair[1];
            
            for(int k = 0; k < 2; k ++){
                if(preferences[x][0] != y && unhappy.count(x) == 0){
                    int i = 0;

                    while(preferences[x][i] != y){
                        int u = preferences[x][i];   // people that x prefers to more than y
                        int v = partner[u], j = 0;   // the partner of u in pairs

                        while(preferences[u][j] != v){
                            if(preferences[u][j] == x){
                                unhappy.insert({x, u});
                                break;
                            }
                            j ++;
                        }

                        i ++;
                    }
                }
                swap(x, y);   // swap x and y, repeat the above process
            }
        }
        return unhappy.size();
    }
};
