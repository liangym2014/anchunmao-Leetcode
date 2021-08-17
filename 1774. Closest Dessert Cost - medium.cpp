// https://leetcode.com/problems/closest-dessert-cost/

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        //sort baseCosts in ascending order
        sort(baseCosts.begin(), baseCosts.end());
        
        if(baseCosts[0] >= target)
            return baseCosts[0];
        
        unordered_set<int> cost = {0}; // possible costs of topping combinations
        for(auto &t: toppingCosts){
            unordered_set<int> new_values;
            for(auto &c:cost)
                new_values.insert({c + t, c + 2 * t});  //at most two of each type of topping
            
            cost.insert(new_values.begin(), new_values.end());
        }
        
        // sort possible costs of topping combinations in ascending order
        vector<int> sorted_cost(cost.begin(), cost.end());
        sort(sorted_cost.begin(), sorted_cost.end());

        
        int ans = target + 100000; // initialize the closest cost with a large gap to the target
        for(int i = 0; i < baseCosts.size(); i ++){
            if(i && baseCosts[i] == baseCosts[i - 1])
                continue;
            
            if(ans == target)
                return ans;
            
            int top = target - baseCosts[i];
            
            // case 1: baseCosts[i] >= target
            if(top <= 0){
                if((-top) < abs(target - ans))
                    ans = baseCosts[i];
                else if(((-top) == abs(target - ans)) && baseCosts[i] < ans) // equally close to target, return the lower one
                    ans = baseCosts[i];
                continue;
            }
            
            // case 2: baseCosts[i] < target
            auto itr = lower_bound(sorted_cost.begin(), sorted_cost.end(), top); // *itr >= top
            int _top = *prev(itr, 1); // *prev(itr, 1) < top
            
            if(itr != sorted_cost.end() && (*itr - top) < (top - _top))
                _top = *itr;

            int sum = baseCosts[i] + _top, diff = abs(target - sum);
            
            if (diff < abs(target - ans))
                ans = sum;
            else if((diff == abs(target - ans)) && sum < ans) // equally close to target, return the lower one
                ans = sum;
        }

        return ans;
    }
};
