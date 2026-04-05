const int N = 10007;

struct entry {
    int time;
    int value;
};

bool compare(entry& a, entry& b) {
    if (a.time == b.time) return a.value < b.value; 
    return a.time < b.time;
}

entry T[N];
entry entries[N];
int answears[N];

class MyCalendarTwo {
    int n = 0;
private:
    void addToArray(entry a) {
        T[n] = a;
        n++;
    }

    bool sortAndBuildSweepingLine() {
        sort(T, T + n, compare);
        answears[0] = T[0].value;
        for(int i = 1; i < n; i++) {
            answears[i] = answears[i-1] + T[i].value;
            if(answears[i] >= 3) {
                return false;
            }
        }
        return true;
    }

public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        entry start; start.time = startTime; start.value = 1;
        entry end; end.time = endTime; end.value = -1;
        addToArray(start);
        addToArray(end);
        if(sortAndBuildSweepingLine()) {
            for(int i = 0; i < n; i++) {
                entries[i] = T[i];
            }
            return true;
        } else {
            n -= 2;
            for(int i = 0; i < n; i++) {
                T[i] = entries[i];
            }
            return false;
        }
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */