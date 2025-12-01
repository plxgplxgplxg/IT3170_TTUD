#include <bits/stdc++.h>
using namespace std;

int m, n; //m giao vien, n mon hoc
// moi gv chi day dc 1 so mon, cap mon xung dot tg
// k the dc day boi cung 1 gv

//in ra min so mon lon nhat ma gv ban nhat p day

set<int> can_teach[11]; //tap cac mon ma gv t day dc
int conflict[31][31]; //=1 neu mon i xug dot j
int load[11]; //gv t hien dang day bnh mon
int teacher[31]; // gv dang day mon i

int currMaxLoad = INT_MIN;
int res_load = INT_MAX;

void input() {
    cin >> m >> n;
    for(int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            conflict[i][j] = 0;
        }
    }
    memset(load, 0, sizeof load);
    for (int i = 1; i <= m; ++i) {
        int k; cin >> k;
        for (int j = 1; j <= k; ++j) {
            int tmp;
            cin >> tmp;
            can_teach[i].insert(tmp);
        }
    }

    int cfl;
    cin >> cfl;
    for (int i = 1; i <= cfl; ++i) {
        int x,y;
        cin >> x >> y;
        conflict[x][y] = 1;
        conflict[y][x] = 1;
    }
}

bool check(int t, int c) {
    if(can_teach[t].count(c) == 0) return false;

    for(int i = 1; i < c; ++i) {
        if (i != c && teacher[i] == t && conflict[i][c] == 1) return false;
    }
    return true;
}

void Try(int c) {
    for (int t = 1; t <= m; ++t) {
        if (check(t, c)) {
            teacher[c] = t;
            ++load[t];
            int temp = currMaxLoad;
            currMaxLoad = max(currMaxLoad, load[t]);

            if (c == n) {
                res_load = min (res_load, currMaxLoad);
            } else {
                if (currMaxLoad < res_load) Try(c + 1);
            }

            --load[t];
            currMaxLoad = temp;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    Try(1);

    cout << res_load << endl;
    return 0;
}