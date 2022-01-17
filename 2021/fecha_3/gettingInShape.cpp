/**
 * Generate all the fibonaccis up to N. Then do the following:
 * 1. Make n = N
 * 2. Find the fibonacci k, such as n % fibo[k] == 0
 * 3. Push k into a queue Q
 * 4. Make n = n / fibo[k] and repeate the process from step 2.
 * 5. Once n == 1, the values of Q indicates how many 'A's you need to print, and the size of Q indicated how many 'B's
 *  you need to print.
 *
 *  For example: n = 10
 *  10 % fibo[4] (5) == 0 -> Q = [4]
 *  2 % fibo[2] (2) == 0 -> Q = [4 2]
 *  1 -> For each value of Q[i] print Q[i] - 1 'A's and then a 'B. In this case AAABAB
 *
 */

#include <vector>
#include <iostream>
#include <string>
using namespace std;

bool solutionFound;
vector<long long> fibo;

void generateFibo(long long);
void getInShape(long long, vector<int> &, int);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    long long n;
    cin >> n;
    
    generateFibo(n);
    
    if (n == 1) {
        cout << "B\n";
    } else {
        vector<int> F;
        solutionFound = false;
        getInShape(n, F, (int)fibo.size() - 1);
        
        if (!solutionFound) {
            cout << "IMPOSSIBLE\n";
        }
    }
    
    return 0;
}

void getInShape(long long num, vector<int> &F, int n) {
    if (num == 1) {
        solutionFound = true;
        for (int i = 0; i < F.size(); i++) {
            for (int j = 0; j < F[i] - 1; j++) {
                cout << "A";
            }
            cout << "B";
        }
        cout << "\n";
        
        return;
    }
    
    for (int i = n; i > 1 && !solutionFound; i--) {
        if (num % fibo[i] == 0) {
            F.push_back(i);
            getInShape(num / fibo[i], F, i);
            F.pop_back();
        }
    }
}

void generateFibo(long long n) {
    fibo.push_back(1);
    fibo.push_back(1);
    long long num = 2;
    long long i = 2;
    while (num <= n) {
        num = fibo[i - 1] + fibo[i - 2];
        i++;
        fibo.push_back(num);
    }
}
