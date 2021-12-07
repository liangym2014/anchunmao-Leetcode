// https://leetcode.com/problems/maximal-network-rank/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if(roads.empty())
            return 0;
        
        vector<set<int>> nodes(n);
        for(auto &cnt: roads){
            nodes[cnt[0]].insert(cnt[1]);
            nodes[cnt[1]].insert(cnt[0]);            
        }
        
        map<int, vector<int>> cnt_count;
        for(int i = 0; i < nodes.size(); i ++){
            if(nodes[i].empty())
                continue;
            
            cnt_count[nodes[i].size()].push_back(i);
        }

        int ans;
        
        if(cnt_count.rbegin()->second.size() > 1){
            ans = 2 * cnt_count.rbegin()->first - 1;
            vector<int> index = cnt_count.rbegin()->second;

            for(int i = 0; i < index.size(); i ++){
                int idx1 = index[i];

                for(int j = i + 1; j < index.size(); j ++){
                    int idx2 = index[j];
                    if(!nodes[idx1].count(idx2)){
                        return ++ ans;
                    }
                }
            }            
        }
        else{
            ans = cnt_count.rbegin()->first;
            int idx1 = (cnt_count.rbegin()->second)[0];

            auto it = ++ cnt_count.rbegin();
            ans += it->first - 1;
            vector<int> index2 = it->second;

            for(int j = 0; j < index2.size(); j ++){
                int idx2 = index2[j];
                if(!nodes[idx1].count(idx2)){
                    return ++ ans;
                }
            }

        }
        return ans;
    }
};
