#include <iostream>
#include <queue>
using namespace std;

int board[502][502];
int vis[502][502];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    int mx = 0; // 그림의 최대크기
    int num = 0; // 그림의 갯수

    // BFS의 시작점 위치 (i, j) 찾는 반복문
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0 || vis[i][j]) continue;
            // 그림이 아니거나(0), 이미 방문했으면 패스
            // i, j에서 BFS를 시작하기 위한 세팅
            // 새로운 그림의 시작점
            num++;
            queue<pair<int, int> > Q;
            vis[i][j] = 1;
            Q.push({i, j});
            int area = 0;
            while(!Q.empty()) {
                // 큐에서 하나씩 pop할때 마다 넓이를 1 증가시킨다
                area++;
               auto cur = Q.front(); Q.pop();

               for(int dir = 0; dir < 4; dir++) {
                   int nx = cur.first + dx[dir];
                   int ny = cur.second + dy[dir];
                   if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                   if(vis[nx][ny] || board[nx][ny] != 1) continue;
                   vis[nx][ny] = 1;
                   Q.push({nx, ny});
               }
            }
            mx = max(mx, area);
        }
    }
    cout << num << '\n' << mx;
}