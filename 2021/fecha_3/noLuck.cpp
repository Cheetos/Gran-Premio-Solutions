/**
 * https://stackoverflow.com/questions/39363745/find-the-number-of-elements-greater-than-x-in-a-given-range
 */

#include <vector>
#include <iostream>
#include <algorithm>
#define oo 100000000
using namespace std;

class Node {
    public:
    int value;
    int index;
    int a;
    int b;
    bool isQuery;
    bool isHappy;
        
    Node (int value = 0, int index = 0, bool isQuery = false, bool isHappy = false, int a = 0, int b = 0) {
        this->value = value;
        this->index = index;
        this->isQuery = isQuery;
        this->isHappy = isHappy;
        this->a = a;
        this->b = b;
    }
    
    bool operator < (const Node &b) const {
        if (this->value == b.value) {
            return this->isQuery < b.isQuery;
        }
        
        return this->value > b.value;
    }
};

int Y, N;
vector<Node> X;
vector<int> T;
vector<int> result;

void updateBIT(int, int);
int queryBIT(int);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int a, p, f, num;
    bool isHappy;
    
    cin >> Y >> N;
    for (int i = 0; i < Y; i++) {
        cin >> num;
        X.push_back(Node(num, i + 1));
    }
    
    T.resize(Y + N + 1, 0);
    result.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> a >> p >> f;
        isHappy = (p > X[a - 1].value) ? false : true;
        X.push_back(Node(p, i, true, isHappy, a, a + f));
    }
    
    sort(X.begin(), X.end());
    
    for (int i = 0; i < X.size(); i++) {
        if (!X[i].isQuery) {
            updateBIT(X[i].index, 1);
        } else if (X[i].isHappy) {
            result[X[i].index] = 0;
        } else {
            result[X[i].index] = queryBIT(X[i].b) - queryBIT(X[i].a);
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << result[i] << "\n";
    }
    
    return 0;
}

void updateBIT(int i, int v) {
    while (i <= Y) {
        T[i] += v;
        i += (i & -i);
    }
}

int queryBIT(int i) {
    int res = 0;
    while (i > 0) {
        res += T[i];
        i -= (i & -i);
    }
    
    return res;
}
