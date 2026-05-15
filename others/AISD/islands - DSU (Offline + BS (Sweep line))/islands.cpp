#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 20;
const int max_N = 1e3 + 7;
int grid[max_N][max_N];
bool isLand[max_N][max_N];

struct Point{
    int val, y, x;
    
    // konstruktor domyślny bo okazuje sie ze stworzenie customowego konstruktora
    // usuwa domyślny konstruktor
    Point() : val(0), y(0), x(0) {}
    
    Point(int v, int i, int j): val(v), y(i), x(j) {}
    
    bool operator<(const Point& other) const {
        return val < other.val;
    }
    
    bool operator<(const int otherVal) const {
        return val < otherVal;
    }
    
    bool operator<=(const Point& other) const {
        return val <= other.val;
    }
};

const int max_points = 1e6;
Point points[max_points];

const int max_time = 1e5 + 7;
int times[max_time];
int results[max_time];

pair<int, int> getIndexesOfRange(int leftVal, int rightVal, int N) {
    auto itLeft = std::lower_bound(points, points + N, leftVal);
    auto itRight = lower_bound(points, points + N, rightVal);
    int leftIndex = std::distance(points, itLeft);
    int rightIndex = std::distance(points, itRight);
    return {leftIndex, rightIndex};
}

// union find
pair<int, int> R[max_N][max_N];
pair<int, int> find(pair<int, int> a) {
    if(a == R[a.first][a.second]) return a;
    return R[a.first][a.second] = find(R[a.first][a.second]);
}

int currRes = 0;
void uni(pair<int, int> a, pair<int, int> b) {
    auto [y, x] = a;
    auto [u, c] = b;
    pair<int, int> Ra = find(a);
    pair<int, int> Rb = find(b);
    if(isLand[y][x] && isLand[u][c] && Ra != Rb) {
        currRes--;
        R[Ra.first][Ra.second] = Rb;
    }
}

void connectLands(int y, int x) {
    // up
    if(y != 0) uni({y, x}, {y - 1, x});
    // right
    uni({y, x}, {y, x + 1});
    // down
    uni({y, x}, {y + 1, x});
    //left
    if(x != 0) uni({y, x}, {y, x - 1});
}

int main() {
	int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j]; 
            points[(i * m) + j] = {grid[i][j], i, j};
        }
    }
    
    int N = n * m;
    sort(points, points + N);
    
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> times[i];
    }
    
    int previousTime = INF;
    int currTime;
    for(int i = t - 1; i >= 0; i--) {
        currTime = times[i] + 1;
        auto [l, r] = getIndexesOfRange(currTime, previousTime, N);
        for(int x = l; x < r; x++) {
            auto [val, b, a] = points[x];
            currRes++;
            isLand[b][a] = true;
            R[b][a] = {b, a};
            connectLands(b, a);
        }
        
        results[i] = currRes;
        previousTime = currTime;
    }
    
    for(int i = 0; i < t; i++) cout << results[i] << " ";
}
