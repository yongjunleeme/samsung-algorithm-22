int N;
int board[15][15];

void bfs_init(int map_size, int map[10][10]) {
  N = map_size;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      board[i+1][j+1] = map[i][j];
    }
  }
}

struct point
{
  int x;
  int y;
};

int bfs(int x1, int y1, int x2, int y2) {
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int dist[15][15];
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      dist[i][j] = -1;

  struct point q[100];
  int front, rear;
  front = rear = -1;
  q[++rear] = {y1, x1};

  dist[y1][x1] = 0;
  while(front != rear){

    auto cur = q[++front];
    int curX = cur.x;
    int curY = cur.y;
    for(int dir = 0; dir < 4; dir++){
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];

      if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
      if(dist[nx][ny] >= 0 || board[nx][ny]) continue;
      dist[nx][ny] = dist[curX][curY] + 1;
      q[++rear] = {nx, ny};
    }
  }
  return dist[y2][x2];
}
