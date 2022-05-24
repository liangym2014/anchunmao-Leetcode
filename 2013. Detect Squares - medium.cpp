// https://leetcode.com/problems/detect-squares/
class DetectSquares {
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        m[point[0]][point[1]] ++;
    }
    
    int count(vector<int> point) {
        int row = point[0], col = point[1];  // point1: (row, col)
        int p3, ans = 0;
        
        if(!m.count(row))
            return 0;
        
        for(auto &[col2, p2]: m[row]){
            int a = abs(col2 - col);   // point2: (row, col2), a: edge of the square

            if(a == 0)
                continue;

            for(auto row3: {row - a, row + a}){
                if(m.count(row3)){
                    if(m[row3].count(col)){ // point3: (row3, col)
                        p3 = m[row3][col];

                        if(m[row3].count(col2)) //point4: (row3, col2)
                            ans += p2 * p3 * m[row3][col2];
                    }
                }
            }
        }
        return ans;
    }
    
private:
    unordered_map<int, unordered_map<int, int>> m;  // key: row, value:(col, count)
};
