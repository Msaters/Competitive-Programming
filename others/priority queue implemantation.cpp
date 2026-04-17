#include <bits/stdc++.h>
#include <functional>
using namespace std;

template <typename T>
class minHeap {
private:
    function<bool(const T&, const T&)> compare; // t1 > t2
    T* arr;
    int tail; // index of next node
    
    void heapifyDown(int i) {
        if(2*i >= tail) return; // node
        if(2*i == tail - 1) {
            if(compare(arr[i], arr[2*i])) swap(arr[i], arr[2*i]); // just one child
            return;
        }
        
        // two children
        if(compare(arr[2*i], arr[2*i + 1])) { // arr[2*i] > arr[2*i + 1]
            if(compare(arr[i], arr[2*i + 1])) {
                swap(arr[i], arr[2*i + 1]);
                heapifyDown(2*i + 1);
            }
        } else { // arr[2*i] <= arr[2*i + 1]
            if(compare(arr[i], arr[2*i])) {
                swap(arr[i], arr[2*i]);
                heapifyDown(2*i);
            }
        }
    }
    
public:
    minHeap(function<bool(const T&, const T&)> compare, T* arr) {
        this->compare = compare;
        this->arr = arr;
        tail = 1;
    }
    
    void push(T elem) {
        int i = tail;
        arr[i] = elem;
        
        while(i != 1) {
            if(compare(arr[i/2], arr[i])) swap(arr[i/2], arr[i]);
            i >>= 1;
        }
        tail++;
    }
    
    void pop() {
        if(tail == 1) return; // no nodes left
        swap(arr[1], arr[tail-1]);
        tail--;
        heapifyDown(1);
    }
    
    T top() {
        return arr[1];
    }
    
    bool empty() {
        return tail == 1;
    }
};


const int N = 1e5 + 7;
vector<pair<int, int>> G[N]; // neighour, distance
long long dist[N];
bool vis[N];

const int M = 1e6 + 7;
pair<int, long long> arr[M]; // array for minHeap

void dijkstra() {
    minHeap<pair<int, long long>> pq(
        [](const pair<int, long long>& a, const pair<int, long long>& b) { 
            return a.second > b.second; 
        }, 
        arr
    );
    
    pq.push({1, 0});
    
    while(!pq.empty()) {
        auto [i, d] = pq.top(); pq.pop();
        if(!vis[i]) {
            vis[i] = true;
            dist[i] = d;
            
            for(pair<int, int> w : G[i]) {
                auto [j, e] = w;
                if(!vis[j]) {
                    pq.push({j, (long long) d + e});
                }
            }
        }
    }
}

const int INF = 1e9;

int main() {
	// your code goes here
	int n, m, k;
	cin >> n >> m >> k;
	
	for(int i = 0; i <= n; i++) dist[i] = INF;
	
	for(int i = 0; i < m; i++) {
	    int a, b, d; cin >> a >> b >> d;
	    G[a].push_back({b, d});
	    G[b].push_back({a, d});
	}
	
	dijkstra();
	
    long long result = 0;
    for(int i = 0; i < k; i++) {
        int q; cin >> q;
        if(!vis[q]) {
            cout << "NIE";
            return 0;
        }
        
        result += 2 * dist[q];
    }
    
    cout << result;
    return 0;
}
