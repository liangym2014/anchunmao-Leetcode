// https://leetcode.com/problems/move-pieces-to-obtain-a-string/
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        // position in start, where requests for a 'L' to match target, 
        // or needa to remove redundant 'R' to match target.
        stack<int> requestL, redundantR;
        stack<int> seq;  // position of 'L' or 'R' in start where matches target
        
        for(int i = 0; i < n; i ++){
            if(target[i] == start[i]){
                if(target[i] != '_') 
                    seq.push(i);
                continue;
            }
            
            if(target[i] == 'L'){
                if(start[i] == 'R')  // a collision of leftward 'L' and rightward 'R' appears
                    return false;
                requestL.push(i);
            }
            else if(target[i] == 'R'){
                // if no redundant R could be moved to here
                if(redundantR.empty()) return false;
                
                // if start[i] == 'L' (which needs to move leftward), or 
                // somewhere on the left still asks for a 'L', a collision of leftward 'L' and rightward 'R' appears
                if(start[i] == 'L' || !requestL.empty()) return false;
                
                // now ensure the last redundantR can move to i, 
                // that means elements between this lastR and i must be 'R'
                int lastR = redundantR.top();
               
                while(!seq.empty() && seq.top() > lastR){
                    if(start[seq.top()] == 'L')
                        return false;
                    seq.pop();  // 'R'
                }
                
                redundantR.pop();
            }
            else{ //target[i] == '_'
                if(start[i] == 'R'){
                    redundantR.push(i);
                    continue;
                }
                
                // if start[i] == 'L', there must be somewhere on the left asks for a 'L'.
                // also somewhere on the left should not have redundant 'R', 
                // otherwise a collision of leftward 'L' and rightward 'R' appears
                if(requestL.empty() || !redundantR.empty()) return false;
                
                int lastL = requestL.top();
                // ensure start[i] can move to last requestL
                // that means elements between this lastL and i must be 'L'
                while(!seq.empty() && seq.top() > lastL){
                    if(start[seq.top()] == 'R')
                        return false;
                    seq.pop();  // 'L'
                }

                requestL.pop();                    
            }
        }
        return requestL.empty() && redundantR.empty();
        
    }
};
