#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void solveTestCase(int n, int m, vector<string>& grid) {
    vector<string> result = grid;  // Copy the grid to mark cells
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // We need to find free cells and their boundary cells
    queue<pair<int, int>> toVisit;
    
    // Start by finding boundary cells for S
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') {
                // Check if it's a boundary cell
                bool isBoundary = false;
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m || grid[ni][nj] == '.') {
                        isBoundary = true;
                        break;
                    }
                }
                if (isBoundary) {
                    toVisit.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
    }

    // Perform BFS/DFS to propagate the S cells
    int countS = 0;
    while (!toVisit.empty() && countS <= 15 * (n * m)) {
        auto [x, y] = toVisit.front();
        toVisit.pop();
        result[x][y] = 'S';
        countS++;
        
        // Check the four adjacent cells and propagate if they are free and not visited
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                toVisit.push({nx, ny});
            }
        }
    }
    
    // Print the result grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (result[i][j] == '#') {
                cout << '#';
            } else if (result[i][j] == 'S') {
                cout << 'S';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
        
        solveTestCase(n, m, grid);
    }

    return 0;
}
