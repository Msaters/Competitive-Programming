const int N = 1e5 + 7;
const int maxPosition = 1e9 + 7;
struct wallsDestroyed {
    int maxLeft;
    int maxRight;
    int bulletEndR;
};

wallsDestroyed dp[N];
pair<int, int> robotsInfo[N];
int n = 0, w = 0;

class Solution {
private:
    int numberOfWallsFromXtoY(int posX, int posY, vector<int>& walls) {
        if(posX > posY) return 0;
        auto start = lower_bound(walls.begin(), walls.end(), posX);
        auto end = upper_bound(walls.begin(), walls.end(), posY) - 1;
        if(end == start && *start != walls[start - walls.begin()]) return 0;
        return end - start + 1;
    }

public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        n = robots.size();
        w = walls.size();
        for(int i = 0; i < n; i++) {
            robotsInfo[i] = {robots[i], distance[i]}; // robotPosition robotShootDistance
        }

        sort(robotsInfo, robotsInfo + n);
        for(int i = 0; i < n; i++) printf("[%d, %d] ", robotsInfo[i].first, robotsInfo[i].second);
        cout << endl;
        sort(walls.begin(), walls.end());
        for(int i = 0; i < w; i++) printf("%d ", walls[i]);
        cout << endl;

        // fill dp[0]
        int bulletEnd = max(0, robotsInfo[0].first - robotsInfo[0].second);
        int WallsFromBulletEndToRobotPos = numberOfWallsFromXtoY(bulletEnd, robotsInfo[0].first, walls);
        dp[0].maxLeft = WallsFromBulletEndToRobotPos;

        if(n > 1)
            dp[0].bulletEndR = min(robotsInfo[0].first + robotsInfo[0].second, robotsInfo[1].first - 1);
        else
            dp[0].bulletEndR = min(robotsInfo[0].first + robotsInfo[0].second, maxPosition);
        dp[0].maxRight = numberOfWallsFromXtoY(robotsInfo[0].first, dp[0].bulletEndR, walls);

        for(int i = 1; i < n; i++) {
            //printf("dp[i-1], i-1: %d, maxLeft: %d, maxRight: %d, bulltetEndR: %d, pos: %d, dist: %d\n", i-1, dp[i-1].maxLeft, dp[i-1].maxRight, dp[i-1].bulletEndR, robotsInfo[i-1].first, robotsInfo[i-1].second);

            bulletEnd = max(robotsInfo[i-1].first + 1, robotsInfo[i].first - robotsInfo[i].second);
            WallsFromBulletEndToRobotPos = numberOfWallsFromXtoY(bulletEnd, robotsInfo[i].first, walls);
            
            dp[i].maxLeft = max(WallsFromBulletEndToRobotPos -              
                            numberOfWallsFromXtoY(bulletEnd, dp[i-1].bulletEndR, walls) + dp[i-1].maxRight,
                            dp[i-1].maxLeft + WallsFromBulletEndToRobotPos);
            if(i == n-1) {
                dp[i].bulletEndR = min(robotsInfo[i].first + robotsInfo[i].second, maxPosition);
            } else {
                dp[i].bulletEndR = min(robotsInfo[i].first + robotsInfo[i].second, robotsInfo[i+1].first - 1);
            }
            dp[i].maxRight = max(dp[i-1].maxRight, dp[i-1].maxLeft) +
                            numberOfWallsFromXtoY(robotsInfo[i].first, dp[i].bulletEndR, walls);
            //printf("dp[i], i: %d, maxLeft: %d, maxRight: %d, bulltetEndR: %d\n", i, dp[i].maxLeft, dp[i].maxRight, dp[i].bulletEndR);
            //printf("WallsFromBulletEndToRobotPos: %d\n", WallsFromBulletEndToRobotPos);
            //printf("WallsFromRobotPosbulletEndR: %d\n", numberOfWallsFromXtoY(robotsInfo[i].first, dp[i].bulletEndR, walls));
        }

        return max(dp[n-1].maxLeft, dp[n-1].maxRight);
    }
};