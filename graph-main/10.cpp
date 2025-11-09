#include <iostream>

using namespace std;

int board[100][100];
int m, n;

void dfs(int r, int c) {
if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 0) {
return;
}

board[r][c] = 2;

dfs(r + 1, c);
dfs(r - 1, c);
dfs(r, c + 1);
dfs(r, c - 1);
}

int main() {
cin >> m;
cin >> n;

for (int i = 0; i < m; ++i) {
for (int j = 0; j < n; ++j) {
cin >> board[i][j];
}
}

for (int j = 0; j < n; ++j) {
if (board[0][j] == 0) {
dfs(0, j);
}
if (board[m - 1][j] == 0) {
dfs(m - 1, j);
}
}

for (int i = 0; i < m; ++i) {
if (board[i][0] == 0) {
dfs(i, 0);
}
if (board[i][n - 1] == 0) {
dfs(i, n - 1);
}
}

for (int i = 0; i < m; ++i) {
for (int j = 0; j < n; ++j) {
if (board[i][j] == 0) {
board[i][j] = 1;
} else if (board[i][j] == 2) {
board[i][j] = 0;
}
}
}

for (int i = 0; i < m; ++i) {
for (int j = 0; j < n; ++j) {
cout << board[i][j] << (j == n - 1 ? "" : " ");
}
cout << endl;
}

return 0;
}

