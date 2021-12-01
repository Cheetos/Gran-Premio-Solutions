/**
 * Keep adding elements into a queue, once the sum of the elements of the queue exceeds the storage
 * capacity, start to remove elements from the queue from the front. The value of R is the minimum 
 * size of the queue in the whole process (when the sum exceeds the storage capacity), 
 * and the value of L is the location when the queue is minimum minus the queue size.
 */

#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;
 
int main() {
	cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    stringstream ss;
    long long n, m, num, storageCapacity, sumTotal;
    string str, strCapacity;
    queue<long long> Q;
    
    cin >> n >> str;
    m = str.length() - 1,
    
    strCapacity = str.substr(0, m);
    ss << strCapacity;
    ss >> storageCapacity;
    
    if (str[m] == 'G') {
        storageCapacity *= 1024;
    } else if (str[m] == 'T') {
        storageCapacity *= 1048576;
    }
    
    long long minStackPos = -1;
    long long minStackSize = n;
    sumTotal = 0;
    for (long long i = 0; i < n; i++) {
        cin >> num;
        Q.push(num);
        sumTotal += num;
        
        if (sumTotal > storageCapacity) {
            while (sumTotal > storageCapacity) {
                sumTotal -= Q.front();
                Q.pop();
            }
 
            if (Q.size() < minStackSize) {
                minStackSize = (int)Q.size();
                minStackPos = i - minStackSize + 1;
            }
        }
    }
    
    cout << minStackSize << " " << minStackPos << "\n";
    
	return 0;
}