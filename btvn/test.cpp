#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

const int MAX = 100; // Adjust as needed
int grid[MAX][MAX];
int rows = 6;
int cols = 6;

// Function to print the grid
void printGrid() {
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

// Function to check if a cell is within grid bounds
bool isValid(int x, int y) {
    return x >= 1 && x <= rows && y >= 1 && y <= cols;
}

// BFS to fill the region
void fillRegion(int startX, int startY) {
    // Directions for moving up, down, left, right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    queue<pair<int, int>> q;
    q.push({startX, startY});
    grid[startX][startY] = 2;  // Temporary marker for visited cells

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (const auto& dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];

            if (isValid(newX, newY) && grid[newX][newY] == 0) {
                grid[newX][newY] = 2;  // Mark as visited
                q.push({newX, newY});
            }
        }
    }
}

// Function to fill boundaries and enclosed regions
void fillBoundaries() {
    // Fill the boundary cells using BFS
    for (int i = 1; i <= rows; ++i) {
        if (grid[i][1] == 0) fillRegion(i, 1);
        if (grid[i][cols] == 0) fillRegion(i, cols);
    }
    for (int j = 1; j <= cols; ++j) {
        if (grid[1][j] == 0) fillRegion(1, j);
        if (grid[rows][j] == 0) fillRegion(rows, j);
    }

    // Convert all temporary markers (2) to 0
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            if (grid[i][j] == 0) {
                grid[i][j] = 1;  // Fill enclosed regions with 1
            } else if (grid[i][j] == 2) {
                grid[i][j] = 0;  // Convert temporary markers back to 0
            }
        }
    }
}

int main() {
    // Input the grid
    cout << "Enter the grid values (6x6):" << endl;
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            cin >> grid[i][j];
        }
    }

    fillBoundaries();
    printGrid();

    return 0;
}
