/**
 * backtracking with memoization, store in X[row][column] the length of the maximum
 * path starting in position (row, column)
 */ 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> grid;
vector<vector<int>> X;
int n, m;
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int backtracking(int, int, int);
int main() {
	cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    X = vector<vector<int>> (n, vector<int>(m, -1));
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maxLen = max(maxLen, backtracking(i, j, grid[i][j] - 'A'));
        }
    }
    
    cout << maxLen << "\n";
    
    
	return 0;
}

int backtracking(int row, int column, int idx) {
    if (row < 0 || row >= n || column < 0 || column >= m) {
        return 0;
    }
    
    if (idx >= ALPHABET.length() || grid[row][column] != ALPHABET[idx]) {
        return 0;
    }
    
    if (X[row][column] != -1) {
        return X[row][column];
    }
    
    int maxLen = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            maxLen = max(maxLen, backtracking(row + i, column + j, idx + 1) + 1);
        }
    }
    
    X[row][column] = maxLen;
    return maxLen;
}