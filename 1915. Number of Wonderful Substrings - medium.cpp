// https://leetcode.com/problems/number-of-wonderful-substrings/

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        unordered_map<int, int> counter;
        // each bit represents the number of the corresponding letter.
        // rightmost bit -> 'a', leftmost bit -> 'j'.
        //on each bit, '1' means odd number, '0' means even number.
        bitset<10> acc(0);

        for(auto &w: word){
            acc.flip(w - 'a');
            int num_acc = acc.to_ulong();
           
            // for word[0: current], at most one letter appears an odd number of times, this's a qualified substring
            if(bitset<10>(num_acc).count() < 2)
                ans ++;
            
            // for word[current - prev], if all letters appear even number of times, that's a qualified substring 
            ans += counter[num_acc];
            
            // for word[current - prev], only one letter appears an odd number of times, that's a qualified substring
            for(int shift = 0; shift < 10; shift ++)
                ans += counter[num_acc ^ (1 << shift)];

            counter[num_acc] ++;            
        }

        return ans;
    }
};
