// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size(), dist = 0;
        bool* visited = (bool*)malloc(n);
        memset(visited, false, n);
        
        vector<vector<int>> edges(n);
        for(auto &e: allowedSwaps){
            edges[e[0]].push_back(e[1]);
            edges[e[1]].push_back(e[0]);
        }
        
        unordered_map<int, int> m;
        vector<int> cc;  //connect component
        
        for(int i = 0; i < n; i ++){
            if(visited[i])
                continue;

            dfs(visited, edges, cc, i);
            
            for(auto &node: cc)
                m[source[node]] ++;

            for(auto &node: cc){
                if(!m.count(target[node]))
                    dist ++;
                else if((-- m[target[node]]) == 0)
                    m.erase(target[node]);
            }

            m.clear();
            cc.clear();
        }
        return dist;
    }
    
    void dfs(bool visited[], vector<vector<int>> &edges, vector<int> &cc, int cur){
        visited[cur] = true;
        cc.push_back(cur);
        
        for(auto &nxt: edges[cur]){
            if(visited[nxt])
                continue;

            dfs(visited, edges, cc, nxt);
        }
    }
};
