//https://leetcode.com/problems/walking-robot-simulation-ii/
class Robot {
private:
    int width, height, row, col, dir, p;
    vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1,0}, {0, -1}}; // east, north, west, south
public:
    Robot(int width, int height): width(width), height(height), dir(0), row(0), col(0) {
        p = 2 * (width - 2 + height);
    }
    
    void step(int num) {
        if(num >= p){
            num %= p;
            if(row == 0){
                if(col == 0 && dir == 0)
                    dir = 3;
                else if((col + 1 == height) && dir == 3)
                    dir = 2;
            }
            else if(row + 1 == width){
                if(col == 0 && dir == 1)
                    dir = 0;
                else if((col + 1 == height) && dir == 2)
                    dir = 1;
            }
        }

        int r = directions[dir].first, c = directions[dir].second, old_r = row, old_c = col;
        row += r * num;
        col += c * num;
        
        while(num){
            int step = num;
            if(row < 0){
                step = old_r;
                row = 0;
            }
            else if(row >= width){
                step = width - old_r - 1;
                row = width - 1;
            }
            else if(col < 0){
                step = old_c;
                col = 0;
            }
            else if(col >= height){
                step = height - old_c - 1;
                col = height - 1;
            }
            
            num -= step;

            if(num == 0)
                break;
            
            dir = (dir + 1) % 4;
            r = directions[dir].first;
            c = directions[dir].second;
            old_r = row;
            old_c = col;
            row += r * num;
            col += c * num;
        }

    }
    
    vector<int> getPos() {
        return {row, col};
    }
    
    string getDir() {
        switch(dir){
            case 0: 
                return "East";
            case 1:
                return "North";
            case 2:
                return "West";
            default:
                return "South";
        }
    }
};
