#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100001

using namespace std;

class Node {
    public:

    int a;
    int b;
    int maxGold;
    
    Node(int a = 0, int b = 0, int maxGold = 0) {
        this->a = a;
        this->b = b;
        this->maxGold = maxGold;
    }
};

int n, m, leafNodeStart, leafNodeEnd;
int gold[N];
int graph[N][2];
vector<Node> segmentTree;

void buildSegmentTree();
int findMaxGold(int, int, int);
void updateSegmentTree(int, int);

int main() {
    int k, i, maxGold, a, b;
    
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &gold[i], &graph[i][0], &graph[i][1]);
    }
    
    buildSegmentTree();
    
    for (i = n - 1; i >= 0; i--) {
        k = i + leafNodeStart;
        a = i + graph[i][0] + leafNodeStart;
        b = i + graph[i][1] + leafNodeStart;
        
        maxGold = findMaxGold(a, b, 0);
        updateSegmentTree(k, maxGold);
    }
    
    printf("%d\n", segmentTree[0].maxGold);
	
	return 0;
}

void updateSegmentTree(int k, int maxGold) {
    int left, right;
    
    segmentTree[k].maxGold += maxGold;
    k = (k % 2 == 0) ? k / 2 - 1 : k / 2;
    
    while(k >= 0) {
        left = 2*k + 1;
        right = 2*k + 2;
        segmentTree[k].maxGold = max(segmentTree[left].maxGold, segmentTree[right].maxGold);
        k = (k % 2 == 0) ? k / 2 - 1 : k / 2;    
    }
}

int findMaxGold(int a, int b, int k) {
    int maxGoldLeft, maxGoldRight;
    int left = 2*k + 1;
    int right = 2*k + 2;
    
    if(a > leafNodeEnd) {
        return 0;
    }
    
    if(b > leafNodeEnd) {
        b = leafNodeEnd;
    }
    
    if(a == segmentTree[k].a && b == segmentTree[k].b) {
        return segmentTree[k].maxGold;
    }
    
    if(a <= segmentTree[left].b && b >= segmentTree[right].a) {
        maxGoldLeft = findMaxGold(a, segmentTree[left].b, left);
        maxGoldRight = findMaxGold(segmentTree[right].a, b, right);
        return max(maxGoldLeft, maxGoldRight);
    } else if (b <= segmentTree[left].b) {
        return findMaxGold(a, b, left);
    } else if(a >= segmentTree[right].a) {
        return findMaxGold(a, b, right);
    }
    
    return 0;
}

void buildSegmentTree() {
    int i, j, s, p, val, parent, maxGold;
    
    s = 0;
    p = 1;
    while (n > p) {
        s += p;
        p *= 2;
    }
    
    leafNodeStart = s;
    leafNodeEnd = s + p - 1;
    segmentTree.resize(s + p);
    for (i = leafNodeStart, j = 0; i <= leafNodeEnd; i++, j++) {
        val = (i < s + n) ? gold[j] : 0;
        segmentTree[i] = Node(i, i, val);
    }
    
    for(i = leafNodeEnd; i > 0; i -= 2) {
        parent = i / 2 - 1;
        maxGold = max(segmentTree[i - 1].maxGold, segmentTree[i].maxGold);
        segmentTree[parent] = Node(segmentTree[i - 1].a, segmentTree[i].b, maxGold);
    }
}
