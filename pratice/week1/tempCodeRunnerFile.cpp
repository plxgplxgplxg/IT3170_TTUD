#include <queue>
#include <iostream>
using namespace std;

 queue<pair<int, int>> qe;
    int n, m, r, c; // nxm, start at r,c
    int a[1005][1005], dist[1005][1005];
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
 

int main () {
    cin >> n >> m >> r >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            dist[i][j] = 0;
        }
    }

    qe.push({r, c});
    dist[r][c] = 0;
    a[r][c] = 1;

    while (!qe.empty()) {
        auto u = qe.front(); qe.pop();

        for (int i = 0; i < 4; i++) {
            int x = u.first + dx[i];
            int y = u.second + dy[i];

            if (x == 0 || x == n + 1 || y == 0 || y == m + 1) {
                cout << dist[u.first][u.second] + 1 << "\n";
                return 0;
            }

            if (a[x][y] == 0) {
                dist[x][y] = dist[u.first][u.second] + 1;
                qe.push({x, y});
                a[x][y] = 1;
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}