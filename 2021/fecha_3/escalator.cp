/**
 * Kind of simulation, for each person I need to know if escalator is going in the 
 * same direction or the opposite. If it is in the same direction just jump over, otherwise, if
 * escalator is not stopped I need to wait.
 */ 

#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, t, d, currentDir, stopTime;
    vector<int> waitingLine(2, 0);
    
    currentDir = -1;
    stopTime = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> d;
        
        // Do nothing especial with the first person
        if (currentDir == -1) {
            currentDir = d;
            stopTime = t + 10;
            continue;
        }
        
        // Arrived afert it stopped? 
        if (t >= stopTime) {
            // Wait for people in the ohter direction
            if (escalator[(currentDir + 1) % 2] > 0) {
                escalator[(currentDir + 1) % 2] = 0;
                stopTime += 10;
            }
            
            if (d != currentDir) {
                // I am going in the same direction as the people in the other direction?
                stopTime = t + 10;
                currentDir = d;
            } else if (t >= stopTime) {
                // I am going in the opposite direction and waited until the escalator stopped
                stopTime = t + 10;
                currentDir = d;
            } else {
                // I am going in the opposite direction and I have to wait
                currentDir = (currentDir + 1) % 2;
                waitingLine[d]++;
            }
        } else {
            if (d == currentDir) {
                // Is going the in the same direciton, so jump over
                stopTime = t + 10;
            } else {
                // Is going in the opposite direction, I have to wait
                waitingLine[d]++;
            }
        }
    }
    
    if (waitingLine[(currentDir + 1) % 2] > 0) {
        stopTime += 10;
    }
    
    cout << stopTime << "\n";
    
	return 0;
}
