/*
https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
*/

/**
 * @param {string} n
 * @return {number}
 */
var minPartitions = function(n) {
    mx = 0;
    
    for(i = 0; i < n.length; i ++)
        mx = Math.max(mx, Number(n[i]));
    
    return mx;
    
};
