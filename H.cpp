#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define N 21
#define oo 200000000
using namespace std;

class ProblemCombination {
    public:
    long long score;
    long long value;
    long long nProblems;
    
    ProblemCombination(long long score = 0, long long value = 0, long long nProblems = 0) {
        this->score = score;
        this->value = value;
        this->nProblems = nProblems;
    }
    
    bool operator < (const ProblemCombination &b) const {
        return this->value < b.value;
    }
};

long long n, lowerBound, minProblems, totalPoints, grade, nCombinations;
long long problemPoints[N];
vector<ProblemCombination> P;


void getCombinations(long long, long long, long long, long long);

int main() {
    long long num, k;
    
	totalPoints = 0;
	scanf("%lld %lld", &n, &grade);
	for (int i = 0; i < n; i++) {
	    scanf("%lld", &problemPoints[i]);
	    totalPoints += problemPoints[i];
	}
	
	minProblems = oo;
	getCombinations(0, 0, 0, 0);

	sort(P.begin(), P.end());
	
	printf("%lld %lld\n", minProblems, nCombinations);
	for (long long i = 0; i < P.size(); i++) {
	    if (P[i].nProblems > minProblems) {
	        continue;
	    }
	    
	    k = 0;
	    num = P[i].value;
	    printf("%lld", P[i].score);
	    while (num >> k > 0) {
	        if (num >> k & 1) {
	            printf(" %lld", k + 1);
	        }
	        
	        k++;
	    }
	    printf("\n");
	}
	
	return 0;
}

void getCombinations(long long pos, long long k, long long score, long long bmask) {
    long long curGrade = floor(((double)score / (double)totalPoints) * 100.0);
    //printf("curGrade = %lld\n", curGrade);
    if (curGrade >= grade) {
        if (pos < minProblems) {
            minProblems = pos ;
            nCombinations = 1;
        } else if (pos == minProblems) {
            nCombinations++;
        }
    
        P.push_back(ProblemCombination(curGrade, bmask, pos));
        return;
    }
    
    if(pos >= n) {
        return;
    }
    
    for (long long i = k; i < n; i++) {
        getCombinations(pos + 1, i + 1, score + problemPoints[i], bmask + (1 << i));
    }
}
