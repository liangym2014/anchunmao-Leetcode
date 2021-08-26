//https://leetcode.com/problems/find-the-winner-of-the-circular-game/
class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int> dlist;
        for(int i = 1; i <= n; i ++)
            dlist.push_back(i);
        
        int cur = 0;
        
        while(dlist.size() > 1){
            int last = (cur + k - 1) % dlist.size();

            if(last == (dlist.size() - 1)){
                dlist.pop_back();
                cur = 0;
            }
            else{
                dlist.erase(next(dlist.begin(), last));
                cur = last;
            }            
        }
        return dlist.front();
    }
};
