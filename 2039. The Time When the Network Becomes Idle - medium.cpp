// https://leetcode.com/problems/the-time-when-the-network-becomes-idle/
class nodes{
private:
    vector<int> dist;
    vector<vector<int>> edges;
public:
    nodes(vector<vector<int>>& edges, int &n):dist(n, INT_MAX), edges(n){
        dist[0] = 0;
        
        for(int i = 0; i < edges.size(); i ++){
            int j = edges[i][0], k = edges[i][1];
            this->edges[j].push_back(k);
            this->edges[k].push_back(j);
        }
    }
    
    void bfs(){
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int f = q.front(), d = dist[f] + 1;
            q.pop();

            for(auto &next: edges[f]){
                if(d < dist[next]){
                    dist[next] = d;
                    q.push(next);
                }
            }
        }
    }
    
    int cal_idle_time(vector<int>& patience){
        int ans = 0;
        for(int i = 1; i < dist.size(); i ++){
            int t = dist[i] * 2, p = patience[i];

            if(t <= p)
                ans = max(ans, t);
            else{
                int start = (t / p - !(t % p)) * p;
                ans = max(ans, start + t);
            }
        }
        return ans + 1;
    }
};

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        nodes ns(edges, n);
        ns.bfs();
        return ns.cal_idle_time(patience);
    }
};
