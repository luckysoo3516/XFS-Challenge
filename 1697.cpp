// 1차원에서의 BFS
// 상,하,좌,우가 아닌 -1, +1, *2 칸만큼 탐색할 수 있다.

#include <queue>
#include <iostream>
using namespace std;
#define X first
#define Y second

int n, k;
int dist[1000002];

int main(void) {
    cin >> n >> k;
    fill(dist, dist+100001, -1);
    queue<int> Q;
    Q.push(n);
    dist[n] = 0;
    while(dist[k] == -1) {
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur-1, cur+1, cur*2}) {
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << dist[k];
}