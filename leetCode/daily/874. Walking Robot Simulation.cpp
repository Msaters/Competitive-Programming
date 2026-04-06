class Solution {
private:
    int direction = 0;
    long long hashMultiplayer = 6 * 1e6 + 7;

    long hashFunction(int x, int y) {
        return y*hashMultiplayer + x;
    }

    long euklides(int x, int y) {
        return x*x + y*y;
    }

    void changeDirection(int turn) {
        if(turn == -1) {
            direction++;
            direction %= 4;
        } else {
            direction--;
            if(direction < 0) direction += 4;
        }
    }

    pair<int, int> getVectorFromDirection() {
        switch (direction) {
            case 0: return {0, 1}; // north
            case 1: return {1, 0}; // east
            case 2: return {0, -1}; // south
            case 3: return {-1, 0}; // west
        }
        return {0, 0};
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        long result = 0;
        int x = 0, y = 0;
        unordered_set<long long> obstaclesSet;
        for(auto obstacle : obstacles) {
            int x = obstacle[0], y = obstacle[1];
            obstaclesSet.insert(hashFunction(x, y));
        }

        for(int command : commands) {
            if(command == -1 || command == -2) {
                changeDirection(command);
            }

            for(int k = 0; k < command; k++) {
                auto [i, j] = getVectorFromDirection();
                if(obstaclesSet.contains(hashFunction(x+i, y+j))) break;
                x += i; y += j;
            }

            result = max(result, euklides(x, y));
        }

        return result;
    }
};