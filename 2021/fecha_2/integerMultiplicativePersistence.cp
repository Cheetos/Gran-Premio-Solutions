/**
 * Compute the IMP recusively and use memoization to avoid calculate the same value multiple times
 */ 

#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> impMap;

int integerMultiplicativePersistence(int);
int main() {
	cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int nTests, n;
    
    cin >> nTests;
    while (nTests-- > 0) {
        cin >> n;
        cout << integerMultiplicativePersistence(n) << "\n";
    }
    
	return 0;
}

int integerMultiplicativePersistence(int n) {
    if (n < 10) {
        return 0;
    }
    
    if (impMap.find(n) != impMap.end()) {
        return impMap[n];
    }
    
    int p = 1;
    while (n > 0) {
        p *= (n % 10);
        n /= 10;
    }
    
    impMap[n] = integerMultiplicativePersistence(p) + 1;
    return impMap[n];
}