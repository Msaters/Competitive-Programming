
//solved

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> MinimalCost[14];
const int N = 531441 + 9;

int main() {
    int n; cin >> n;
    int sizeN = 1;
    for(int i = 0; i < n; i++) {
        sizeN *= 3;
    }
    
    for(int i = 0; i < sizeN; i++) {
        char a; cin >> a;
        MinimalCost[0].push_back({a - '0', 1});
    }
    
    int actSizeN = sizeN;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < actSizeN; j+=3) {
            int actSum = 0;
            vector<int> CostOfZeroes; vector<int> CostOfOnes;
            for(int k = j; k < j+3; k++) {
                actSum += MinimalCost[i][k].first;
                if(MinimalCost[i][k].first == 1) {
                    CostOfOnes.push_back(MinimalCost[i][k].second);
                } else {
                    CostOfZeroes.push_back(MinimalCost[i][k].second);
                }
                //cout << MinimalCost[i][k].first << " " << MinimalCost[i][k].second << " | ";
            }
            
            int actCost = 0;
            if(actSum > 1) {
                sort(CostOfOnes.begin(), CostOfOnes.end());
                for(int l = 0; l < actSum - 1; l++) {
                    actCost += CostOfOnes[l];
                }
                MinimalCost[i+1].push_back({1, actCost});
            }
            else {
                sort(CostOfZeroes.begin(), CostOfZeroes.end());
                for(int l = 0; l < 2 - actSum; l++) {
                    actCost += CostOfZeroes[l];
                }
                MinimalCost[i+1].push_back({0, actCost});
            }
        }
        //cout << endl;
        actSizeN /= 3;
    }
    
    cout << MinimalCost[n][0].second;

    return 0;
}
