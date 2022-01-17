/**
 * The ith element has two numbers, the blockId and the color, if the element in position blockId has
 * a different color, then we print N. 
 */ 

#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, k, blockId, color;
    bool isSortingPossible = true;
    unordered_map<int, pair<int, int>> blockMap;
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> blockId >> color;
        blockMap[i] = make_pair(blockId, color);
    }
    
    for (int i = 1; i <= n; i++) {
        blockId = blockMap[i].first;
        color = blockMap[i].second;
        
        if (blockMap[blockId].second != color) {
            isSortingPossible = false;
            break;
        }
    }
    
    if (isSortingPossible) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }
    
	return 0;
}
