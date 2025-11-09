#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>>& grid, int m, int n) {
    // boundary or water check
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
        return;

    grid[i][j] = 0; // mark as visited (turn land to water)

    // explore all 4 directions
    dfs(i + 1, j, grid, m, n); // down
    dfs(i - 1, j, grid, m, n); // up
    dfs(i, j + 1, grid, m, n); // right
    dfs(i, j - 1, grid, m, n); // left
}

int main() {
    int m, n;
    cin >> m;
    cin >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                count++;
                dfs(i, j, grid, m, n);
            }
        }
    }

    cout << count << endl;
    return 0;
}
