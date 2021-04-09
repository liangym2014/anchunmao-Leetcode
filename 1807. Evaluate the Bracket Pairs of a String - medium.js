/*
https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
*/

/**
 * @param {string} s
 * @param {string[][]} knowledge
 * @return {string}
 */
var evaluate = function(s, knowledge) {
    map = new Map(knowledge);

    ans = "";
    start = 0;
    pos1 = s.indexOf('(', start);
    
    while(pos1 != -1){
        ans += s.slice(start, pos1);
        pos2 = s.indexOf(')', pos1);
        
        key = s.slice(pos1 + 1, pos2);
        ans += map.has(key)? map.get(key):'?';
        
        start = pos2 + 1;
        pos1 = s.indexOf('(', start);        
    }
    
    return ans + s.slice(start);

};
