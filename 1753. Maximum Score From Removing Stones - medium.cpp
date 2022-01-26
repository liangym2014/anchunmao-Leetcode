// https://leetcode.com/problems/maximum-score-from-removing-stones/
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // sort a, b, c, so that a >= b >= c
        if(a < b)
            swap(a, b);
        if(c > a){
            swap(c, a);
            swap(b, c);
        }
        else if(c > b)
            swap(b, c);
        // cout<<a<<","<<b<<","<<c<<endl;
        
        if (a >= (b + c))  return b + c;
        return a + ((b + c - a) >> 1);
    }

};
