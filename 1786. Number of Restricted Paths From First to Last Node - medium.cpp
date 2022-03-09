// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/
bool cmp(const pair<int, int> &l, const pair<int, int> &r){
    return l.first > r.first;
}

class Solution {
private:
    vector<int> distance, paths;
    vector<vector<pair<int, int>>> nodes;
    
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        nodes = vector<vector<pair<int, int>>>(1 + n);
        for(auto &e: edges){
            nodes[e[0]].push_back({e[1], e[2]});
            nodes[e[1]].push_back({e[0], e[2]});
        }

        distance = vector<int>(n + 1, INT_MAX);
        distance[n] = 0;
        
        vector<pair<int, int>> frontier(1, {0, n});  // min heap, key: distance from node n to i, value: index i
        
        while(!frontier.empty()){
            pop_heap(frontier.begin(), frontier.end(), cmp);
            pair<int, int> f = frontier.back();
            frontier.pop_back();
            
            int dist = f.first, node = f.second;

            if(dist > distance[node])
                continue;

            for(auto &[nxt, w]: nodes[node]){
                int d = dist + w;
                if(d < distance[nxt]){
                    distance[nxt] = d;
                    frontier.push_back({d, nxt});
                    push_heap(frontier.begin(), frontier.end(), cmp);
                }
            }

        }
        paths = vector<int>(1 + n);
        return dfs(n);
    }
    
    int dfs(int start){
        if(start == 1)
            return 1;
        
        int res = 0;
        for(auto &[nxt, w]: nodes[start]){
            if(distance[nxt] != INT_MAX && distance[nxt] > distance[start]){
                if(paths[nxt] < 0)
                    continue;
                res += paths[nxt]? paths[nxt]: dfs(nxt);
                res %= 1000000007;
            }
        }

        paths[start] = res? res: (-1);
        return res;
    }
};
