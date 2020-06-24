#include <queue>
#include <string>
#include <iostream>
using namespace std;
#define X first
#define Y second
int n, m;
string board[102];
int dist[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main(void) {
    cin >> n >> m;
    // 입력이 한줄씩 띄어쓰기 없이 들어오기 때문에 string으로 받는다.
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }
    // dist 배열을 fill() 을 이용해 -1로 초기화.
    // 방문하지 않으면 -1, 방문했으면 거리를 갖고 있음.
    for(int i = 0; i < n; i++) {
        fill(dist[i], dist[i]+m, -1);
    }
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0] = 1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny <0 || ny >= m) continue;
            // 중요. dist가 -1이 아니면 이미 방문했다는 뜻
            // board의 값은 string이기 때문에 '1'이 들어있다!
            if(dist[nx][ny] != -1 || board[nx][ny] != '1') continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << dist[n-1][m-1];
}