// 시작점이 여러개인 BFS -> 큐에 한번에 넣고 시작한다
#include <queue>
#include <iostream>
using namespace std;
#define X first
#define Y second

int n, m;
int mx = 0;
int board[1002][1002];
int dist[1002][1002];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int main(void) {
    int empty = 0; // 토마토가 없는 칸의 갯수
    int cnt = 0; // 나중에 익지 않은 토마토의 갯수
    queue<pair<int, int>> Q;
    cin >> m >> n;

    for(int i = 0; i < n; i++)
        fill(dist[i],dist[i] + m,-1);

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                Q.push({i, j});
                dist[i][j] = 0;
            }
            else if(board[i][j] == -1) empty++;
        }
    }

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >=n || ny <0 || ny >= m) continue;
            if(board[nx][ny] == -1 || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            mx = max(dist[nx][ny], mx);
            Q.push({nx, ny});
        }
    }

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(dist[i][j] == -1) cnt++;
        }
    }
    mx = cnt > empty ? -1 : mx;
    cout << mx;
}