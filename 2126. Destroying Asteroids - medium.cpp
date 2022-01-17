// https://leetcode.com/problems/destroying-asteroids/
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int i = 0;
        long long acc = mass;
        while(i < asteroids.size() && asteroids[i] <= acc)
            acc += asteroids[i ++];
        
        return i == asteroids.size();
    }
