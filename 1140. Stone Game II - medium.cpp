// https://leetcode.com/problems/stone-game-ii/
class Solution {
private:
    vector<vector<int>> mx, mn;
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        for(int i = 1; i < n; i ++)
            piles[i] += piles[i - 1];

        if(n < 3) return piles.back();
        mx = vector<vector<int>>(n, vector<int>(n, 0));
        mn = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        return alice_collect(piles, 0, 1, true);
    }
    
    int alice_collect(vector<int>& piles, int start, int M, bool alice){
        int acc = 0, n = piles.size();
        if(start >= n)
            return acc;

        int end = start + 2 * M, lim = min(n, end), prev = start - 1;

        if(alice){ //Alice's turn
            if(end > n && mx[start].back())
                return mx[start].back();

            if(mx[start][M])   return mx[start][M];

            for(int i = start; i < lim; i ++)
                acc = max(acc, piles[i] + alice_collect(piles, i + 1, max(M, i - prev), !alice));

          
            acc -= (start? piles[prev]: 0);
            mx[start][M] = acc;
        }
        else{ // Bob's turn, Bob take piles[start:i] and want to return the minimum of Alice's choice
            if(end > n && mn[start].back()!= INT_MAX)
                return mn[start].back();
              
            if(mn[start][M] != INT_MAX)   return mn[start][M];
            
            acc = INT_MAX;
            for(int i = start; i < lim; i ++)
                acc = min(acc, alice_collect(piles, i + 1, max(M, i - prev), !alice)); 
            
            mn[start][M] = acc;
        }

        return acc;
    }
};
