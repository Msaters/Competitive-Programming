const int alfabetSize = 26;
const int rowSize = 6;
const int columnSize = 5;
const int INF = 1e9;

const int WordLength = 302;
int dp[WordLength][columnSize][rowSize][columnSize][rowSize];  // dp[i][point x.y][point x.x][point y.y][point y.x]

struct point {
    int x, y;
};

unordered_map<char, point> keyboard;


class Solution {
private:
    point getPointFromIndex(int index) {
        return {index % rowSize, index / rowSize};
    }

    int distanceBetweenPoints(point& a, point& b) {
        return abs(a.x - b.x) + abs(a.y - b.y);
    }

public:
    int minimumDistance(string word) {
        // building keyboard
        for(char i = 'A'; i < 'A' + alfabetSize; i++) {
            int index = (int) i - 'A';
            keyboard[i] = getPointFromIndex(index);
        }

        int n = word.length();
        for(int i = 0; i <= n; i++) {
            for(int k = 0; k < alfabetSize; k++) {
                auto [x, y] = getPointFromIndex(k);
                for(int l = 0; l < alfabetSize; l++) {
                    auto [xprim, yprim] = getPointFromIndex(l);
                    if(i == 0) dp[i][y][x][yprim][xprim] = 0;
                    else dp[i][y][x][yprim][xprim] = INF;
                }
            }
        }


        int result = INF;
        for(int i = 1; i <= n; i++) {
            char currCharacter = word[i - 1];
            point currPoint = getPointFromIndex((int) currCharacter - 'A');

            // I move finger X to current point
            for(int pointYIndex = 0; pointYIndex < alfabetSize; pointYIndex++) {
                point fingerY = getPointFromIndex(pointYIndex); // I don't move my figer Y
                for(int pointXIndex = 0; pointXIndex < alfabetSize; pointXIndex++) {
                    point fingerX = getPointFromIndex(pointXIndex);
                    dp[i][currPoint.y][currPoint.x][fingerY.y][fingerY.x] = min(dp[i][currPoint.y][currPoint.x][fingerY.y][fingerY.x], 
                    dp[i-1][fingerX.y][fingerX.x][fingerY.y][fingerY.x] + distanceBetweenPoints(fingerX, currPoint));

                    //printf("fingerX: [%d %d], fingetY: [%d, %d], dp[i-1][fingerX][fingerY]: %d, distanceXtoNewFinger: %d dp[i][newFInger][fingerY]: %d\n", fingerX.x, fingerX.y, fingerY.x, fingerY.y, dp[i-1][fingerX.y][fingerX.x][fingerY.y][fingerY.x], distanceBetweenPoints(fingerX, currPoint), dp[i][currPoint.y][currPoint.x][fingerY.y][fingerY.x]);

                    if(i == n) {
                        result = min(result, dp[i][currPoint.y][currPoint.x][fingerY.y][fingerY.x]);
                    }
                }
            }

            // I move finger Y to current point
            for(int pointXIndex = 0; pointXIndex < alfabetSize; pointXIndex++) {
                point fingerX = getPointFromIndex(pointXIndex); // I don't move my figer X
                for(int pointYIndex = 0; pointYIndex < alfabetSize; pointYIndex++) {
                    point fingerY = getPointFromIndex(pointYIndex);
                    dp[i][fingerX.y][fingerX.x][currPoint.y][currPoint.x] = min(dp[i][fingerX.y][fingerX.x][currPoint.y][currPoint.x], 
                    dp[i-1][fingerX.y][fingerX.x][fingerY.y][fingerY.x] + distanceBetweenPoints(fingerY, currPoint));

                    //printf("fingerX: [%d %d], fingetY: [%d, %d], dp[i-1][fingerX][fingerY]: %d, distanceYTonNewFinger: %d dp[i][FingerY][newFInger]: %d\n", fingerX.x, fingerX.y, fingerY.x, fingerY.y, dp[i-1][fingerX.y][fingerX.x][fingerY.y][fingerY.x], distanceBetweenPoints(fingerY, currPoint), dp[i][fingerX.y][fingerX.x][currPoint.y][currPoint.x]);

                    if(i == n) {
                        result = min(result, dp[i][fingerX.y][fingerX.x][currPoint.y][currPoint.x]);
                    }
                }
            }
        }

        return result;
    }
};