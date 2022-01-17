/**
 * The modulos: B^0 % (B + 1), B^1 % (B + 1), B^2 % (B + 1), ... looks like this:
 * 1, B, 1, B, 1, B, 1, B, ....
 * 
 * Calculate the modulos for each D[i] * B^(i) and store it in X[i].
 * The sum of all values of X is modSum
 * If modSum % (B + 1) is zero, print 0 0
 * For the i-th digit do the following (from most-significant to less-significant):
 * if i is odd then newDigit = a, otherwise newDigit = (B + 1 - a)%(B + 1), where a = modSum - X[i]
 * Check if newDigit < D[i], if it is, then the result is the pair L - i, newDigit. 
 */ 

#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
    ios_base::sync_with_stdio(0);
    int B, L;
    
    cin >> B >> L;
    vector<int> X(L);
    vector<int> D(L);
    int powerMod;
    int modSum = 0;
    for (int i = L - 1; i >= 0; i--) {
        cin >> D[i];
        powerMod = (i % 2 == 0) ? 1 : B;
        X[i] = (D[i] * powerMod) % (B + 1);
        modSum += X[i];
    }
    
    int digitChanged = 0;
    int valueChanged = 0;
    if (modSum % (B + 1) == 0) {
        cout << "0 0\n";
    } else {
        for (int i = L - 1; i >= 0; i--) {
            powerMod = (i % 2 == 0) ? 1 : B;
            int a = (modSum - X[i]) % (B + 1);
            int newDigit = (B + 1 - a) % (B + 1); 
            if (powerMod == B) {
                newDigit = a;
            }
            
            if (newDigit < D[i]) {
                digitChanged = L - i;
                valueChanged = newDigit;
                break;   
            }
        }
        
        if (digitChanged == 0) {
            cout << "-1 -1\n";
        } else {
            cout << digitChanged << " " << valueChanged << "\n";
        }
    }
    
	return 0;
}