#include <iostream>
#include <algorithm>
using namespace std;
int n;
int val[200000];
int dp[501][501];
int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cin >> val[((i * (i - 1)) / 2) + j + 1];
        }
    }

    dp[1][0] = val[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (j == 0) {
                dp[i][0] = dp[i - 1][0] + val[((i * (i - 1)) / 2) + 1];
            }
            else if (j == i - 1) {
                dp[i][j] = dp[i - 1][j - 1] + val[((i * (i - 1)) / 2) + 1 + j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + val[((i * (i - 1)) / 2) + 1 + j];
            }
        }
    }
    int res = 0;
    for (int j = 0; j < n; j++) {
        res = max(res, dp[n][j]);
    }
    cout << res << "\n";
    return 0;
}