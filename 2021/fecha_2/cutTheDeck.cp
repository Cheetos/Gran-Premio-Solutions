/**
 * Add 1 for each B, and substract 1 for each R, the location where we reach the minimum is where
 * we need to cut the deck
 */ 

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string str;
    int k, nTests, cut, minVal;
    
    cin >> nTests;
    while (nTests-- > 0) {
        cin >> str;
        k = 0;
        cut = 0;
        minVal = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == 'B') {
                k++;
            } else {
                k--;
            }
            
            if (k < minVal) {
                cut = i + 1;
                minVal = k;
            }
        }   
        
        cout << cut << "\n";
    }
    
	return 0;
}
