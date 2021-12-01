/**
 * Maximum number of outstanding spoons: #Total spoons - #full spoons with rice
 * Minimum number of outstanding spoons: max(#Total spoons - R, 0)
 */

#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
	int nTests, C, R, S;
	
    cin >> nTests;	
    while (nTests-- > 0) {
    	cin >> C >> R >> S;
    	
    	int totalSpoons = (C + R) % S == 0 ? (C + R) / S : (C + R) / S + 1;
    	int fullRaisinsSpoons = R % S == 0 ? R / S : R / S + 1;
    	int maxSpoons = totalSpoons - fullRaisinsSpoons;
    	int minSpoons = R >= totalSpoons ? 0 : totalSpoons - R;
    	
    	cout << maxSpoons << " " << minSpoons << "\n";
    }
    
	return 0;
}
