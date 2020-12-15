#include <iostream>
#define M 1000000007
 
using namespace std;
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    long long n, k, t, res;
        
	cin >> t;
	while (t--) {
	    cin >> n >> k;
	    
	    res = 1;
	    res = (((n + 2) * (n + 1)) / 2) % M;
	    res = (res * ((k + 1) % M)) % M;
	    
	    cout << res << "\n";
	}
	
	return 0;
}