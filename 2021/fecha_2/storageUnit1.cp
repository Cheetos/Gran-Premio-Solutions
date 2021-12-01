/**
 * Find the value of R with binary search: O(n log n), then just do one more pass to find the value
 * of L
 */ 

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

vector<long long> C;

bool isStoragePossible(int, long long);

int main() {
	cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    stringstream ss;
    string str, strCapacity;
    int n, m;
    long long num, storageCapacity;
    
    cin >> n >> str;
    m = str.length() - 1,
    
    strCapacity = str.substr(0, m);
    ss << strCapacity;
    ss >> storageCapacity;
    
    if (str[m] == 'G') {
        storageCapacity *= 1024;
    } else if (str[m] == 'T') {
        storageCapacity *= 1048576;
    }
    
    C.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        C[i] = (i == 0) ? num : C[i - 1] + num;
    }
    
    int a = 1;
    int b = n;
    int maxVideos = n;
    int leastVideo = -1;
    
    while(a <= b) {
        int c = (a + b) / 2;
        if (isStoragePossible(c, storageCapacity)) {
            a = c + 1;
            maxVideos = c;
        } else {
            b = c - 1;
        }
    }
    
    for (int i = 0; i < n - maxVideos - 1; i++) {
        long long sa = (i == 0) ? 0 : C[i - 1];
        long long sb = C[i + maxVideos];
        
        if (sb - sa > storageCapacity) {
            leastVideo = i + 1;
            break;
        }
    }
    
    cout << maxVideos << " " << leastVideo << "\n";
    
    
	return 0;
}

bool isStoragePossible(int k, long long storageCapacity) {
    for (int i = 0; i < C.size() - k; i++) {
        long long sa = (i == 0) ? 0 : C[i - 1];
        long long sb = C[i + k - 1];
        
        if (sb - sa >  storageCapacity) {
            return false;
        }
    }
    
    return true;
}
