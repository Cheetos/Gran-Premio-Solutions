/**
 Memoization, store in happinessMap[k] the maximum happiness we can get if we start from activity k, it is stored to avoid
 calculating the same values over and over.
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
    public:
    int startTime;
    int endTime;
    int happiness;
    
    Node(int startTime = 0, int endTime = 0, int happiness = 0) {
        this->startTime = startTime;
        this->endTime = endTime;
        this->happiness = happiness;
    }
};

int n, closingTime;
vector<Node> activities;
unordered_map<int, vector<int>> graph;
unordered_map<int, int> happinessMap;

int findMaximumHappiness(int);
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int happiness, duration, nTimes, startTime, endTime;
    
    cin >> n >> closingTime;
    for (int i = 0; i < n; i++){
        cin >> happiness >> duration >> nTimes;
        for (int j = 0; j < nTimes; j++) {
            cin >> startTime;
            if (startTime >= closingTime) {
                continue;
            }
            
            endTime = startTime + duration;
            activities.push_back(Node(startTime, endTime, happiness));
        }
    }
    
    for (int i = 0; i < activities.size(); i++) {
        if (graph.find(i) == graph.end()) {
            graph[i] = vector<int>();
        }
        
        for (int j = i + 1; j < activities.size(); j++) {
            if (activities[i].endTime <= activities[j].startTime) {
                graph[i].push_back(j);
            } else if (activities[j].endTime <= activities[i].startTime) {
                graph[j].push_back(i);
            }
        }
    }
    
    int maximumHappiness = 0;
    for (auto it = graph.begin(); it != graph.end(); it++) {
        int a = it->first;
        if (happinessMap.find(a) != happinessMap.end()) {
            maximumHappiness = max(maximumHappiness, happinessMap[a]);
        } else {
            maximumHappiness = max(maximumHappiness, findMaximumHappiness(a));
        }
    }
    
    cout << maximumHappiness << "\n";
    
    return 0;
}

int findMaximumHappiness(int v) {
    int maximumHappiness = 0;
    for (int i = 0; i < graph[v].size(); i++) {
        int k = graph[v][i];
        if (happinessMap.find(k) != happinessMap.end()) {
            maximumHappiness = max(maximumHappiness, happinessMap[k]);
        } else {
            maximumHappiness = max(maximumHappiness, findMaximumHappiness(k));
        }
    }
    
    happinessMap[v] = maximumHappiness + activities[v].happiness;
    return happinessMap[v];
}
