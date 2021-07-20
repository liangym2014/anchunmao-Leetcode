// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution {
public:
    int minDeletions(string s) {
        if(s.size() == 1)
            return 0;
        
        vector<int> chars(26);
        for(auto &c: s)
            chars[c - 'a'] ++;
        
        sort(chars.begin(), chars.end());  // sort frequencies in ascending order
        vector<int> final_freq; // frequency after modification of array chars
        int deletion = 0, i = 0;
     
        while(!chars[i])
            i ++;
        
        if(i < 26)
            final_freq.push_back(chars[i ++]);
        
        for(; i < 26; i ++){
            //final_freq not empty
            if(final_freq.back() == chars[i]){ // this frequency already exist
                int j, value; //value: the value that chars[i] is converted to
                
                for(j = final_freq.size() - 2; j >= 0; j --){
                    if(final_freq[j] == chars[i] || (final_freq[j] + 1 == final_freq[j + 1]))
                        continue;
                    
                    value = final_freq[j + 1] - 1;
                    deletion += chars[i] - value;
                    final_freq.insert(final_freq.begin() + j + 1, 1, value);  // insert into final_freq
                    break;

                }
                
                //couldn't find the right place to insert modified chars[i] between final_freq.front() ~ final_freq.back()
                if(j < 0){
                    value = max(0, final_freq[0] - 1); 
                    
                    if(value == 0)
                        deletion += chars[i]; // chars[i] is converted to 0, don't insert into final_freq
                    else{
                        deletion += chars[i] - value;
                        final_freq.insert(final_freq.begin(), 1, value); // insert into final_freq
                    }
                }
            }
            else
                final_freq.push_back(chars[i]);
             
        }
        return deletion;
    }
};
