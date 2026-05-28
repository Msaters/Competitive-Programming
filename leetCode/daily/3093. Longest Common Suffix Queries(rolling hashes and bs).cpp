#define ll long long

ll m1 = 1e7, m2 = 1e9;
ll p1 = 37, p2 = 53;

const int max_word_len = 1e4 + 7;
ll sufHash1[max_word_len];
ll sufHash2[max_word_len];
ll p1_exp[max_word_len];
ll p2_exp[max_word_len];

int sizes[max_word_len];

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        unordered_map<ll, int> M;
        int smallestWordIndex = 0;
        int smallestWordSize = 1e9;

        for(int j = 0; j < wordsContainer.size(); j++) {
            string& word = wordsContainer[j];
            sizes[j] = word.size();
            if(sizes[j] < smallestWordSize) {
                smallestWordSize = sizes[j];
                smallestWordIndex = j;
            }
            int n = word.size();
            p1_exp[n] = 1;
            p2_exp[n] = 1;
            sufHash1[n] = 0;
            sufHash2[n] = 0;

            for(int i = n - 1; i >= 0; i--) {
                p1_exp[i] = (p1_exp[i + 1] * p1) % m1;
                p2_exp[i] = (p2_exp[i + 1] * p2) % m2;
                sufHash1[i] = (sufHash1[i + 1] + word[i] * p1_exp[i]) % m1;
                sufHash2[i] = (sufHash2[i + 1] + word[i] * p2_exp[i]) % m2;
                ll combinedHash = sufHash1[i] + (sufHash2[i] << 32);
                auto it = M.find(combinedHash);
                if(it == M.end()) {
                    M[combinedHash] = j;
                } else {
                    int currJ = it->second;
                    if(sizes[currJ] > sizes[j]) {
                        M[combinedHash] = j;
                    }
                }
            }
        }

        vector<int> indexesOfBiggestSuffixes;
        for(string& word : wordsQuery) {
            int n = word.size();
            p1_exp[n] = 1;
            p2_exp[n] = 1;
            sufHash1[n] = 0;
            sufHash2[n] = 0;

            for(int i = n - 1; i >= 0; i--) {
                p1_exp[i] = (p1_exp[i + 1] * p1) % m1;
                p2_exp[i] = (p2_exp[i + 1] * p2) % m2;

                sufHash1[i] = (sufHash1[i + 1] + word[i] * p1_exp[i]) % m1;
                sufHash2[i] = (sufHash2[i + 1] + word[i] * p2_exp[i]) % m2;
            }

            int l = 0, r = n-1;
            while(l < r) {
                int mid = (l + r) / 2;
                ll combinedHash = sufHash1[mid] + (sufHash2[mid] << 32);
                auto it = M.find(combinedHash);
                if(it == M.end()) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }

            ll finalHash = sufHash1[l] + (sufHash2[l] << 32);
            if(M.find(finalHash) != M.end()) {
                indexesOfBiggestSuffixes.push_back(M[finalHash]);
            } else {
                indexesOfBiggestSuffixes.push_back(smallestWordIndex);
            }
        }

        return indexesOfBiggestSuffixes;
    }
};