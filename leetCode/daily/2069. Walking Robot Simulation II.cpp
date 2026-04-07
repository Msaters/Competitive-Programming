class Robot {
private:
    vector<vector<int>> grid;
    int direction;
    int x, y;
    int m, n;
    int mod;
    
    void turn() {
        direction--;
        direction = direction >= 0 ? direction : direction + 4;
    }

public:
    Robot(int width, int height) {
        m = height; n = width;
        mod = 2*m + 2*n - 4;
        x = 0, y = 0;
        direction = 1;
    }
    
    void step(int num) {
        num = num % mod == 0 ? mod : num % mod;
        while(num > 0) {
            switch(direction) {
                case 0: 
                    if(num + y > m - 1) {
                        num -= (m - 1) - y;
                        y = m - 1;
                        turn();
                    } else {
                        y = num + y;
                        return;
                    }
                    break;
                case 1: 
                    if(num + x > n - 1) {
                        num -= (n - 1) - x;
                        x = n - 1;
                        turn();
                    } else {
                        x = num + x;
                        return;
                    }
                    break;
                case 2: 
                    if(y - num < 0) {
                        num -= y;
                        y = 0;
                        turn();
                    } else {
                        y = y - num;
                        return;
                    }
                    break;
                case 3:
                    if(x - num < 0) {
                        num -= x;
                        x = 0;
                        turn();
                    } else {
                        x = x - num;
                        return;
                    }
                    break;
            }
        }
    }
    
    vector<int> getPos() {
        vector<int> pos = {x, y};
        return pos;
    }
    
    string getDir() {
        switch(direction) {
            case 0: return "North";
            case 1: return "East";
            case 2: return "South";
            case 3: return "West";
        }
        return "None";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */