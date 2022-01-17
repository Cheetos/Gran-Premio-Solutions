/**
 * Check the difference between element i and element i-1, and if the difference is larger or equal
 * than t, then it is rested. 
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t, d, n, prev, meal;
    bool isRested = false;
    
    cin >> t >> d >> n;
    prev = 0;
    for (int i = 0; i < n; i++) {
        cin >> meal;
        if (meal - prev >= t) {
            isRested = true;
            break;
        }
        prev = meal;
    }
    
    if (!isRested && (d - prev >= t)) {
        isRested = true;
    }
    
    if (isRested) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }
    
	return 0;
}
