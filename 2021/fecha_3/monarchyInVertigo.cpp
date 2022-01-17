/**
 Another example where queries must be post-processed.
 1. Build a graph with parent and child relationships. (query type 1)
 2. Store in a queue called "queries" all the ids from the queries of type 2
 2. Start a DFS from node 1, and store in a queue (royalOrder) all the visited nodes in the order they are visited
 3. For each query, mark the current id as visited, then remove all the front elemens from royalOrder that are visited, and print
 the first element on royalOrder.
 */

#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int royalCounter = 1;
queue<int> royalOrder;
queue<int> queries;
unordered_map<int, vector<int>> graph;
unordered_set<int> visited;

void DFS(int);

int main() {
    int q, queryType, royalId;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        cin >> queryType >> royalId;
        if (queryType == 1) {
            graph[royalId].push_back(++royalCounter);
        } else {
            queries.push(royalId);
        }
    }
    
    DFS(1);
    
    while (!queries.empty()) {
        royalId = queries.front();
        visited.insert(royalId);
        while (visited.find(royalOrder.front()) != visited.end()) {
            royalOrder.pop();
        }
        cout << royalOrder.front() << "\n";
        queries.pop();
    }
    
    return 0;
}

void DFS(int k) {
    royalOrder.push(k);
    for (auto it = graph[k].begin(); it != graph[k].end(); it++) {
        DFS(*it);
    }
}
