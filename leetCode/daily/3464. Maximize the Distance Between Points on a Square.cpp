const int points_MAX = 1e3 * 15 + 7;


class Solution {
private:
    long long manDist(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int solveBS(int side, vector<long long>& arr, int k) {
        // CODE FROM EDITORIAL I AM TIRED
         auto check = [&](long long limit) -> bool {
            for (long long start : arr) {
                long long end = start + side * 4LL - limit;
                long long cur = start;
                for (int i = 0; i < k - 1; i++) {
                    auto it = ranges::lower_bound(arr, cur + limit);
                    if (it == arr.end() || *it > end) {
                        cur = -1;
                        break;
                    }
                    cur = *it;
                }
                if (cur >= 0) {
                    return true;
                }
            }
            return false;
        };

        int l = 1, r = side;
        while(l < r) {
            int mid = (l + r + 1)/2;
            if(check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> arr;
        for(auto point : points) {
            long long x = point[0], y = point[1];
            if(y == 0) {
                arr.push_back((long long)x);
                continue;
            }
            if(x == side) {
                arr.push_back((long long) side + y);
                continue;
            }
            if(y == side) {
                arr.push_back((long long)3*side - x);
                continue;
            }
            if(x == 0) {
                arr.push_back((long long)4*side - y);
                continue;
            }
        }
        sort(arr.begin(), arr.end());

        //vector<vector<pair<long long, int>>> dist(points.size(), vector<int>(points.size(), {0, 0})); // dist index
        /*for(int i = 0; i < points.size(); i++) {
            for(int j = 0; j < points.size(); j++) {
                if (i == j) {
                    dist[i][j] = {1e11, i};
                } else {
                    dist[i][j] = j < i ? {4 * side - arr[i] + arr[j], j} : {arr[j] - arr[i], j}; 
                }
            }
        }*/

        // CHANGED IDEA, TO IDEA FROM EDITORIAL

        return solveBS(side, arr, k);
    }

    
};