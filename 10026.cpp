#include <queue>
#include <iostream>
#include <string>
using namespace std;
#define X first
#define Y second
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int n;
string board[102];
int vis[102][102];

int main(void) {
    int rgb = 0; // 적록색약이 아닐 때 구역의 수
    int non_rgb = 0; // 적록색약일 때 구역의 수
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> board[i];
        fill(vis[i], vis[i] + n, 0);
    }

    char color; // 현재 탐색하고 있는 색깔
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            if(vis[i][j]) continue;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({i, j});
            color = board[i][j];
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] || board[nx][ny] != color ) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            rgb++;
        }
    }

    for(int i = 0; i < n; i++){
        fill(vis[i], vis[i] + n, 0);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 'G') board[i][j] = 'R';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            if(vis[i][j] == 1) continue;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({i, j});
            color = board[i][j];
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] == 1 || board[nx][ny] != color ) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            non_rgb++;
        }
    }
    cout << rgb << ' ' << non_rgb;
}