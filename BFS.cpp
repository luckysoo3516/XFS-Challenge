#include <queue>
#include <iostream>
#define X first
#define Y second
using namespace std;
int board[502][502] =
        {{1,1,1,0,1,0,0,0,0,0},
         {1,0,0,0,1,0,0,0,0,0},
         {1,1,1,0,1,0,0,0,0,0},
         {1,1,0,0,1,0,0,0,0,0},
         {0,1,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0} };
// 1이 파란 칸, 0이 빨간 칸에 대응
int n = 7, m = 10;
bool vis[502][502];
// 방문 했는지 안했는지 저장
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> Q;
    vis[0][0] = 1;
    Q.push({0,0});
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        cout << '(' << cur.X << ',' << cur.Y << ") -> ";
        for(int dir = 0; dir < 4 ; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}