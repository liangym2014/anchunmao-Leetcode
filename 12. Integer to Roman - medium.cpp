/*
https://leetcode.com/problems/integer-to-roman/
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> numbers{1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> symbols = {"I", "IV", "V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string ans;
        
        while(num){
            int idx = upper_bound(numbers.begin(), numbers.end(), num) - numbers.begin() - 1;

            string t;
            for(int i = 0, multiple = num / numbers[idx]; i < multiple; ++ i)
                t += symbols[idx];
            
            ans += t;
            num %= numbers[idx];
        }
        return ans;
    }
};
