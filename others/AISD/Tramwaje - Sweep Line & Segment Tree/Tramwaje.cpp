#include <bits/stdc++.h>
using namespace std;

#define f first 
#define s second 

const int N = 2e6 + 7;
pair<int, int> arr[N];

int inc_seq_right[N];
int dec_seq_left[N];
int maxPodciagRight[N];

const int base = 2097152;
struct node {
    int maxSeq;
    int left, right;
};

node segTree[base * 2];

void addVal(int i, int valSeq) {
    i += base;
    segTree[i].maxSeq = valSeq;
    i /= 2;
    
    while(i) {
        segTree[i].maxSeq = max(segTree[2*i].maxSeq, segTree[2*i + 1].maxSeq); 
        i /= 2;
    }
}

int getMax(int v, int l, int r) {
    if(segTree[v].left >= l && segTree[v].right <= r) return segTree[v].maxSeq;
    if(segTree[v].right < l || segTree[v].left > r) return 0;
    return max(getMax(2*v, l, r), getMax(2*v + 1, l, r));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while(t) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            arr[i] = {a, i};
        }
        
        for(int i = 0; i < n; i++) {
            dec_seq_left[i] = 1;
            inc_seq_right[i] = 1;
        }
        
        for(int i = 1; i < n; i++) {
            if(arr[i - 1].f < arr[i].f) {
                dec_seq_left[i] = dec_seq_left[i - 1] + 1;
            }
        }
        
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i].f < arr[i + 1].f) {
                inc_seq_right[i] = inc_seq_right[i + 1] + 1;
            }
        }
        
        for(int i = 0; i < n; i++) {
            maxPodciagRight[i] = inc_seq_right[i];
        }
        
        sort(arr, arr + n, greater<pair<int, int>>());
        
        for(int i = base; i < base * 2; i++) {
            segTree[i] = {0, i-base, i-base};
        }
        for(int i = base - 1; i >= 1; i--) {
            segTree[i] = {0, segTree[2*i].left, segTree[2*i + 1].right};
        }
        
        int maxSequence = 0;
        for(int i = 0; i < n; i++) {
            maxSequence = max({maxSequence, dec_seq_left[i], inc_seq_right[i]});
        }
        
        for(int i = 0; i < n; ) {
            int j = i;
            while(j < n && arr[j].f == arr[i].f) {
                j++;
            }
            
            for(int k = i; k < j; k++) {
                auto [val, id] = arr[k];
                int bestRight = getMax(1, id + 1, n);
                maxPodciagRight[id] = max(maxPodciagRight[id], bestRight);
                maxSequence = max(maxSequence, dec_seq_left[id] + bestRight);
                
            }
            
            for(int k = i; k < j; k++) {
                auto [val, id] = arr[k];
                addVal(id, inc_seq_right[id]); 
            }
            
            i = j;
        }
        
        cout << maxSequence << "\n";
        t--;
    }
}