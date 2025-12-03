#include <iostream>

using namespace std;
const int maxN = 1e3 + 5;
int n, m;
int a[maxN][maxN];
int histogram[maxN][maxN];

int get_left(int col, int row) {
    int height = histogram[row][col];
    int left = col;
    while (left >= 0 && histogram[row][left] >= height) {
        left--;
    }
    return left + 1;
}

int get_right(int col, int row) {
    int height = histogram[row][col];
    int right = col;
    while (right < m && histogram[row][right] >= height) {
        right++;
    }
    return right - 1;
}

int get_max_row(int row) {
    int ans = 0;
    for (int i = 0; i < m; i++)  {
        ans = max(ans, histogram[row][i] * (get_right(i, row) - get_left(i, row) + 1));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];

            if (a[i][j] == 0)
                histogram[i][j] = 0;
            else
                histogram[i][j] = (i == 0 ? 1 : histogram[i-1][j] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, get_max_row(i));
    }
    cout << ans << "\n";
    return 0;
}
