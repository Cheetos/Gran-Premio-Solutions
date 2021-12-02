/**
 Same idea of Sieve of Eratosthenes. For example, for K = 6 we can just grab all binary numbers of 3 digits and concatenate them to form
 6-Binary Repetitive numbers, we know there are 2^3 ninaru numbers of 3 digits, so there must be at  least 2^3 6-Binary repetitive numbers. We can keep concatenating to form 9-Binary Repetitive, 12-Binary Repetitive, and so on. We just need to be careful to not
 count the same number twice.
 
 It is important to pre-calculate the results since there can be multiple cases.
 */

#include <iostream>
#include <vector>
#define N 1000000
#define M 1000000007
using namespace std;

vector<long long> X(N + 1, 0);

void sieve();
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    long long nTests, n;
    
    sieve();
    
    cin >> nTests;
    while (nTests-- > 0) {
        cin >> n;
        cout << X[n] << "\n";
    }
    
    return 0;
}

void sieve() {
    long long p = 2;
    for (long long i = 1; i <= N; i++) {
        long long delta = (p - X[i]) % M;
        if (delta < 0) {
            delta += M;
        }
        
        for (long long j = 2 * i; j <= N; j += i) {
            X[j] = (X[j] + delta) % M;
        }
        
        p = (p * 2) % M;
    }
}
