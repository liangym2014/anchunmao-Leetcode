//https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#define DIST long long
#define LONG_DIST LLONG_MAX

bool cmp(const pair<int, int> &l, const pair<int, int> &r){
    return l.first > r.first;
}

struct node{
    DIST distance = LONG_DIST;
    int paths = 0;  // positive number: valid result; 0: unvisited; -1: deadend
    vector<pair<int, int>> edges;
};

class Solution {
private:
    vector<node> nodes;
    int dest;
    
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        dest = n - 1;  // destination
        nodes.resize(n);
        
        for(auto &e: roads){
            nodes[e[0]].edges.push_back({e[1], e[2]});
            nodes[e[1]].edges.push_back({e[0], e[2]});
        }

        nodes[0].distance = 0;
        vector<pair<DIST, int>> frontier(1, {0, 0});  // min heap, key: distance from node 0 to i, value: index i

        while(!frontier.empty()){
            pop_heap(frontier.begin(), frontier.end(), cmp);
            pair<DIST, int> f = frontier.back();
            frontier.pop_back();

            DIST dist = f.first;
            int node = f.second;

            if(dist > nodes[node].distance)
                continue;

            for(auto &[nxt, w]: nodes[node].edges){
                DIST d = dist + (DIST)w;
                if(d < nodes[nxt].distance){
                    nodes[nxt].distance = d;
                    frontier.push_back({d, nxt});
                    push_heap(frontier.begin(), frontier.end(), cmp);
                }
            }

        }

        return dfs(0);        
    }
    
    int dfs(int start){
        if(start == dest)
            return 1;

        int res = 0;
        for(auto &[nxt, w]: nodes[start].edges){
            DIST target = nodes[nxt].distance;
            int path = nodes[nxt].paths;
            
            if(target != LONG_DIST && target == (w + nodes[start].distance)){
                if(path < 0)
                    continue;
                res += path? path: dfs(nxt);
                res %= 1000000007;
            }
        }

        nodes[start].paths = res? res: (-1);
        return res;
    }
    
};
