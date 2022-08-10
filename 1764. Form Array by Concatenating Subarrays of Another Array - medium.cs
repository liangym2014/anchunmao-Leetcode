// https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/
public class Solution {
    public bool CanChoose(int[][] groups, int[] nums) {
        int m = nums.Length, n = groups.Length, elementNum = 0;
        for(int i = 0; i < n; i ++)
            elementNum += groups[i].Length;  // total number of elements in groups
        
        int start = 0;
        for(int i = 0; i < n; i ++){  // for groups[i]
            bool found = false;
            int lim = groups[i].Length;
            
            while(!found && (start + lim) <= m){
                int j, end = start + lim;
                for(j = start; j < end; j ++){
                    if(nums[j] != groups[i][j - start])
                        break;
                }

                if(j == end){
                    found = true;
                    start = end;
                }
                else
                    start ++;
            }
            if(!found)  return false;
               
            elementNum -= lim;
            
            if(start + elementNum > m) // if the remaining elements in groups more than remaining length of nums
                return false;
        }
        return true;
    }
}
