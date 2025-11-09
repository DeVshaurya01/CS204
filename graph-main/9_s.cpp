#include <iostream>

using namespace std;

int grid[100][100];
int queue_r[10000];
int queue_c[10000];
int queue_time[10000];
int front = 0;
int rear = 0;
int m, n;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void enqueue(int r, int c, int time) {
queue_r[rear] = r;
queue_c[rear] = c;
queue_time[rear] = time;
rear++;
}

bool isQueueEmpty() {
return front == rear;
}

int main() {
cin >> m;
cin >> n;

int freshOranges = 0;

for (int i = 0; i < m; ++i) {
for (int j = 0; j < n; ++j) {
cin >> grid[i][j];
if (grid[i][j] == 1) {
freshOranges++;
} else if (grid[i][j] == 2) {
enqueue(i, j, 0);
}
}
}

int maxTime = 0;

while (!isQueueEmpty()) {
int r = queue_r[front];
int c = queue_c[front];
int time = queue_time[front];
front++;

if (time > maxTime) {
maxTime = time;
}

for (int i = 0; i < 4; ++i) {
int nr = r + dr[i];
int nc = c + dc[i];

if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
grid[nr][nc] = 2;
freshOranges--;
enqueue(nr, nc, time + 1);
}
}
}

if (freshOranges == 0) {
cout << maxTime << endl;
} else {
cout << -1 << endl;
}

return 0;
}


