#include <iostream>
#include <cstdio>
#define N 200001
#define M 1000000007
using namespace std;

long long fact[N], factInv[N];

long long binaryPow(long long, long long, long long);
long long comb(long long, long long, long long);

int main() {
    long long t, a, b, c, n, k, i, j;
    long long combA, combB, combC, combAB, res, prod;
    
    fact[0] = fact[1] = 1;
    factInv[0] = factInv[1] = 1;
    for (i = 2; i < N; i++) {
        fact[i] = (i * fact[i - 1]) % M;
        factInv[i] = binaryPow(fact[i], M - 2, M);
    }

    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &n, &k);

        if(n - k <= 1) {
            printf("0\n");
            continue;
        }
        
        combC = comb(c, k, M);
        combAB = comb(a + b, n - k, M);
        combA = comb(a, n - k, M);
        combB = comb(b, n - k, M);
        res = (combAB - ((combA + combB) % M)) % M;
        if (res < 0) {
            res += M;
        }
        
        res = (res * combC) % M;

        printf("%lld\n", res);
    }
}

long long binaryPow(long long a, long long b, long long m) {
    long long p = 1;
    a = a % m;
    
    while (b > 0) {
        if (b % 2 == 1) {
            p = (p * a) % m;
        }
        a = (a * a) % m;
        b = b / 2;
    }

    return p;
}

long long comb(long long n, long long k, long long p) {
    if (k > n) {
        return 0;
    }
    
    return (((fact[n] * factInv[k]) % p) * factInv[n - k]) % p;
}

