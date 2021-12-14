// https://leetcode.com/problems/cheapest-flights-within-k-stops/
const int inf = 1e7;

struct city{
    vector<pair<int, int>> out;
    int acc = inf; //expense from src to current city
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<city> cities(n);
        
        for(auto &flight: flights){
            int from = flight[0], to = flight[1], price = flight[2];
            cities[from].out.push_back(make_pair(to, price));
        }
        
        cities[src].acc = 0;
        set<int> current({src});
        int ik = 0;
        
        while(ik <= k){
            unordered_map<int, int> frontier;
            
            for(auto &cur: current){
                for(auto &e: cities[cur].out){
                    int next_city = e.first, price = e.second;
                    int expense = cities[cur].acc + price;
                    if(frontier.count(next_city)){
                        if(expense < frontier[next_city])
                            frontier[next_city] = expense;
                    }
                    else if(expense < cities[next_city].acc){
                        frontier[next_city] = expense;
                    }
                }
            }
            ++ ik;
            current.clear();
            
            for(auto &c: frontier){
                cities[c.first].acc = c.second;
                current.insert(c.first);
            }

        }
        return cities[dst].acc == inf? -1: cities[dst].acc;
    }
};
