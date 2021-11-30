// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

bool cmp(const vector<int> &l, const vector<int> &r){
    return l[0] < r[0];
}

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        int first_seat = 0; // the index of 1st seat that is never assigned to anyone
        vector<int> seats; // min heap, keeping all the available seats that're once assigned to someone
        
        for(int i = 0; i < n; i ++){
            times[i].push_back(i);  //{arrival time, leave time, index}
        }
        
        //sort in ascending order of arrival time
        sort(times.begin(), times.end(), cmp);
        
        map<int, vector<int>> leave; // key: leave time, value: occupied seats
        int choice;
        
        for(auto &time: times){
            // release all seats in "leave" with the key <= time[0]
            vector<int> deleted;

            for (auto itr = leave.begin(); itr != leave.end() && itr->first <= time[0]; itr ++){
                vector<int> released_seats = itr->second;
                deleted.push_back(itr->first);

                // release the occupied seats into "seats"
                for(auto &s: released_seats){
                    seats.push_back(s);
                    push_heap(seats.begin(), seats.end(), greater<int>());
                }
            }
            
            // remove all the leaving people in deleted to seats
            for(auto &d: deleted)
                leave.erase(d);

            // take the smallest seat available
            if(seats.empty())
                choice = first_seat ++;
            else{
                choice = seats.front();
                pop_heap(seats.begin(), seats.end(), greater<int>());                
                seats.pop_back();                
            }
            
            if(time[2] == targetFriend)
                break;
            leave[time[1]].push_back(choice);// update leave            
        }
        return choice;
    }
};
