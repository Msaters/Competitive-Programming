const int base = 65536;
const int treeSize = base * 2;

struct treeNode {
    bool isElem;
    int leftDist, rightDist, maxDist;
    int left, right;
};

treeNode segTree[treeSize];
int minBlock = 1e9;
int maxBlock = 0;
bool isLeaf(int x) {
    return x >= base;
}

bool wasAlreadyBuilt = false;
void buildTree() {
    if(wasAlreadyBuilt) return;
    wasAlreadyBuilt = true;

    for(int i = base; i < treeSize; i++) {
        segTree[i].left = i - base;
        segTree[i].right = i - base;
    }

    for(int i = base - 1; i > 0; i--) {
        segTree[i].left = segTree[2*i].left;
        segTree[i].right = segTree[2*i + 1].right;
    }
}

void addNode(int x, int leftDist, int rightDist) {
    x += base;
    segTree[x] = {true, leftDist, rightDist, max(leftDist, rightDist), segTree[x].left, segTree[x].right};
    x >>= 1;
    while(x) {
        segTree[x].isElem = true;
        segTree[x].maxDist = max(segTree[2*x].maxDist, segTree[2*x + 1].maxDist);
        x >>= 1;
    }
}

void clearNode(int x) {
    x += base;
    segTree[x] = {false, 0, 0, 0, segTree[x].left, segTree[x].right};
    x >>= 1;
    while(x) {
        segTree[x].isElem = false;
        segTree[x].maxDist = 0;
        x >>= 1;
    }
}

int maxFreeSpace(int left, int right, int v) {
    if(segTree[v].right < left || segTree[v].left > right) return 0;
    if(segTree[v].right <= right && segTree[v].left >= left) return segTree[v].maxDist;
    return max(maxFreeSpace(left, right, 2*v), maxFreeSpace(left, right, 2*v + 1));
}

int succ(int x) {
    x += base;
    int childDir = x%2; // left = 0, right = 1
    x >>= 1;

    // getting to fork with succ 
    while(childDir == 1 || !segTree[2*x + 1].isElem) { 
        childDir = x%2;
        x >>= 1;
    } 

    // goint to first element of rightChild
    x = 2*x + 1;
    while(!isLeaf(x)) {
        // whenever I can I go to left becasue left is before right
        if(segTree[2*x].isElem) {
            x <<= 1;
        } else {
            x = 2*x + 1;
        }
    }

    return x -= base;
}

int pred(int x) {
    x += base;
    int childDir = x%2; // left = 0, right = 1
    x >>= 1;

    // getting to fork with pred 
    while(childDir == 0 || !segTree[2*x].isElem) { 
        childDir = x%2;
        x >>= 1;
    } 

    // goint to first element of leftChild
    x <<= 1;
    while(!isLeaf(x)) {
        // whenever I can I go to right becasue right is after left
        if(segTree[2*x + 1].isElem) {
            x = 2*x + 1;
        } else {
            x <<= 1;
        }
    }

    return x -= base;
}

void printOneNode(int x) {
    x += base;
    printf("PRINT x: %d, left Dist: %d, right Dist: %d\n", x - base, segTree[x].leftDist, segTree[x].rightDist);
}

void addBlockAndUpdateNeighbours(int x) {
    int leftNeighbour = pred(x);
    int rightNeighbour = succ(x);

    int leftDistance = 0;
    leftDistance = x - leftNeighbour;
    addNode(leftNeighbour, segTree[leftNeighbour + base].leftDist, leftDistance);
    
    int rightDistance = 0;
    rightDistance = rightNeighbour - x;
    addNode(rightNeighbour, rightDistance, segTree[rightNeighbour + base].rightDist);

    addNode(x, leftDistance, rightDistance);
}

void printNode(int x) {
    printf("x: %d, left Dist: %d, right Dist: %d\n", x, segTree[x + base].leftDist, segTree[x + base].rightDist);
    int r = succ(x);
    int l = pred(x);
    x = l;
    printf("leftNeighbour: %d, left Dist: %d, right Dist: %d\n", x, segTree[x + base].leftDist, segTree[x + base].rightDist);
    x = r;
    printf("rightNeighbour: %d, left Dist: %d, right Dist: %d\n", x, segTree[x + base].leftDist, segTree[x + base].rightDist);
}

const int maxRight = 5 * 1e4;
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        buildTree();
        addNode(0, 0, 0);
        addNode(maxRight, 0, 0);

        vector<bool> result;
        vector<int> blocks;

        for(vector<int>& query : queries) {
            if(query[0] == 1) {
                addBlockAndUpdateNeighbours(query[1]);
                blocks.push_back(query[1]);
            } else {
                int predIndex = pred(query[1]);
                int maximumOnRange = 0;
                if(predIndex == 0) {
                    maximumOnRange = query[1];    
                } else {
                    maximumOnRange = max(maxFreeSpace(0, predIndex - 1, 1), query[1] - predIndex);
                }

                
                result.push_back(maximumOnRange >= query[2]);
            }
        }

        for(int block : blocks) {
            clearNode(block);
        }
        return result;
    }
};